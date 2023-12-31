//
// Created by Acyco on 2023-12-31.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

static void handler(int sno , siginfo_t *info, void *ucontext)
{
    printf("1\n");
}

static void handler1(int sno )
{
    printf("1\n");
}

int main()
{
    struct itimerval itv;
    struct sigaction act;

    sigemptyset(&act.sa_mask);
//    act.sa_handler = handler1;
    act.sa_sigaction = handler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGALRM,&act,NULL);

    itv.it_value.tv_usec=0;
    itv.it_value.tv_sec=5;
    itv.it_interval.tv_usec = 0;
    itv.it_interval.tv_sec = 5;

    setitimer(ITIMER_REAL,&itv,NULL);


    while (1)
    {
        printf(".\n");
        sleep(1);
    }
    exit(0);
}