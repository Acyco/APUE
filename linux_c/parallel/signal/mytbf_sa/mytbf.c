//
// Created by Acyco on 2023-12-31.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>


#include "mytbf.h"

typedef void (*sighandler_t)(int);

static struct mytbf_st *job[MYTBF_MAX];
static int inited = 0;
static struct sigaction alrm_sa_save;

struct mytbf_st
{
    int cps;
    int burst;
    int token;
    int pos;
};

static void alrm_action(int s, siginfo_t *infop, void *unused)
{
    int i;


   if(infop->si_code != SI_KERNEL)
       return;

    for (i = 0; i < MYTBF_MAX; i++)
    {
        if (job[i] != NULL)
        {
            job[i]->token += job[i]->cps;
            if (job[i]->token > job[i]->burst)
                job[i]->token = job[i]->burst;
        }
    }
}

static void module_unload()
{
    int i;
    struct itimerval itv;

    sigaction(SIGALRM, &alrm_sa_save, NULL);

    itv.it_interval.tv_sec = 0;
    itv.it_interval.tv_usec =0;
    itv.it_value.tv_usec = 0;
    itv.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &itv, NULL);

    for (i = 0; i < MYTBF_MAX; i++)
        free(job[i]);
}

static void module_load(void)
{
    struct sigaction sa;
    struct itimerval itv;

    sa.sa_sigaction = alrm_action;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGALRM, &sa, &alrm_sa_save);
    /* if error */

    itv.it_interval.tv_sec = 1;
    itv.it_interval.tv_usec = 0;
    itv.it_value.tv_sec = 1;
    itv.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &itv, NULL);
    /* if error */

    atexit(module_unload); // 钩子函数
}


static int get_free_pos()
{
    int i;

    for (i = 0; i < MYTBF_MAX; i++)
    {
        if (job[i] == NULL)
            return i;
    }

    return -1;
}

mytbf_t *mytbf_init(int cps, int burst)
{
    struct mytbf_st *me;
    int pos;

    if (!inited)
    {

        module_load();
        inited = 1;
    }
    pos = get_free_pos();

    if (pos < 0)
        return NULL;

    me = malloc(sizeof(me));
    if (me == NULL)
        return NULL;
    me->token = 0;
    me->cps = cps;
    me->burst = burst;
    me->pos = pos;
    job[pos] = me;
    return me;
}

static int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int mytbf_fetchtoken(mytbf_t *ptr, int size)
{
    struct mytbf_st *me = ptr;
    int n;

    if (size <= 0)
        return -EINVAL;

    while (me->token <= 0)
        pause();

    n = min(me->token, size);

    me->token -= n;
    return n;
}

int mytbf_returntoken(mytbf_t *ptr, int size)
{
    struct mytbf_st *me = ptr;
    if (size <= 0)
        return -EINVAL;

    me->token += size;
    if (me->token > me->burst)
        me->token = me->burst;
    return size;
}

int mytbf_destory(mytbf_t *ptr)
{
    struct mytbf_st *me = ptr;
    job[me->pos] = NULL;
    free(me);
    return 0;
}

