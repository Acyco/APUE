//
// Created by Acyco on 2023-12-31.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "anytimer.h"

static void f2(void *p)
{
    printf("f2():%s\n", p);
}

static void f1(void *p)
{
    printf("f1():%s\n", p);
}

int main()
{

    int job1, job2, job3;
    int res,count = 0;

    puts("Begin!");

    job1 = at_addjob(5, f1, "aaa");
    if (job1 < 0)
    {
        fprintf(stderr, "at_addjob(): %s\n", strerror(-job1));
        exit(1);
    }
    job2 = at_addjob(2, f2, "bbb");
    if (job2 < 0)
    {
        fprintf(stderr, "at_addjob(): %s\n", strerror(-job2));
        exit(1);
    }
    job3 = at_addjob(3, f1, "ccc");
    if (job3 < 0)
    {
        fprintf(stderr, "at_addjob(): %s\n", strerror(-job3));
        exit(1);
    }

   /* res = at_canceljob(job3);
    res = at_canceljob(job3);
    if(res < 0)
    {
        fprintf(stderr,"at_cenceljob():%s\n", strerror(-res));
        exit(1);
    }*/

    res = at_waitjob(job2);
    if(res < 0)
    {
        fprintf(stderr,"at_cenceljob():%s\n", strerror(-res));
        exit(1);
    }

    while (1)
    {
        if(count == 2)
        {
            res = at_pausejob(job1);
            if(res < 0)
            {
                fprintf(stderr,"at_pausejob():%s\n", strerror(-res));
                exit(1);
            }
        }

        if(count == 5)
        {
            res = at_resumejob(job1);
            if(res < 0)
            {
                fprintf(stderr,"at_resumejob():%s\n", strerror(-res));
                exit(1);
            }
        }
        write(1,".",1);
        sleep(1);
        count++;
    }

    puts("End!");
    exit(0);
}