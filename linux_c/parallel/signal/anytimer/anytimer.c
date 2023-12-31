//
// Created by Acyco on 2023-12-31.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include "anytimer.h"

typedef void (*sighandler_t)(int);

static struct at_timer_st* job[JOB_MAX];
static int inited = 0;
static sighandler_t alrm_handler_save;

#define AT_JOB_FLAG_NORMAL 0
#define AT_JOB_FLAG_RUN 1
#define AT_JOB_FLAG_FINISH 2
#define AT_JOB_FLAG_PAUSE 3
#define AT_JOB_FLAG_CANCEL 4

struct at_timer_st
{
    int sec;
    int flag;
    at_jobfunc_t *func;
    void *arg;
};

static void alrm_handler(int s)
{
    int i;

    alarm(1);

    for(i = 0; i < JOB_MAX; i++)
    {
        if(job[i] != NULL)
        {
            if( job[i]->flag == AT_JOB_FLAG_NORMAL){
                job[i]->sec -= 1;
                if(job[i]->sec <= 0 ){
                    job[i]->flag = AT_JOB_FLAG_RUN;
                    job[i]->func(job[i]->arg);
                    job[i]->flag = AT_JOB_FLAG_FINISH;
                }
            }
        }
    }
}

static void module_unload()
{
    int i;
    signal(SIGALRM,alrm_handler_save);
    alarm(0);
    for(i = 0; i < JOB_MAX; i++)
        free(job[i]);
}


static void module_load()
{
    alrm_handler_save = signal(SIGALRM, alrm_handler);
    alarm(1);

    atexit(module_unload);
}

static int get_free_job()
{
    int  i;

    for(i = 0; i < JOB_MAX; i++)
    {
        if(job[i] == NULL)
            return i;
    }
    return -1;
}

int at_addjob(int sec, at_jobfunc_t *jobp , void *arg)
{
    struct at_timer_st *me;
    int pos;

    if(!inited){
        module_load();
        inited = 1;
    }

    pos = get_free_job();
    if(pos < 0)
        return -ENOSPC;

    me = malloc(sizeof(me));
    if(me == NULL)
        return -ENOMEM;

    me->sec = sec;
    me->func = jobp;
    me->arg = arg;
    me->flag = AT_JOB_FLAG_NORMAL;

    job[pos] = me;
    return pos;
}

static struct at_timer_st *getjob(int id)
{
    struct at_timer_st *cur;

    if(id > JOB_MAX -1){
        return NULL;
    }
    cur = job[id];

    return cur;
}


int at_canceljob(int id)
{
    struct at_timer_st *cur;
    cur = getjob(id);
    if(cur == NULL)
        return -EINVAL;

    if(cur->flag == AT_JOB_FLAG_FINISH)
        return -EBUSY;

    printf("%d\n",cur->flag);
    if(cur->flag == AT_JOB_FLAG_CANCEL)
        return -ECANCELED;

    cur->flag = AT_JOB_FLAG_CANCEL;
    return 0;
}


int at_waitjob(int id)
{
    struct at_timer_st *cur;

    cur = getjob(id);
    if(cur == NULL)
        return -EINVAL;

    if(cur->flag == AT_JOB_FLAG_RUN)
        return -EBUSY;

    free(cur);
    job[id] = NULL;

    return 0;
}

int at_pausejob(int id)
{
    struct at_timer_st *cur;

    cur = getjob(id);

    if(cur == NULL)
        return -EINVAL;

    if(cur->flag == AT_JOB_FLAG_RUN)
        return -EBUSY;

    cur->flag = AT_JOB_FLAG_PAUSE;

    return 0;
}

int at_resumejob(int id)
{
    struct at_timer_st *cur;

    cur = getjob(id);
    if(cur == NULL)
        return -EINVAL;

    if(cur->flag == AT_JOB_FLAG_RUN)
        return -EBUSY;

    cur->flag = AT_JOB_FLAG_NORMAL;

    return 0;
}