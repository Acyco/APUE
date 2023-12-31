//
// Created by Acyco on 2023-12-31.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void int_handler(int s)
{
    write(1,"!", 1);
}

int main()
{
    int i, j ;
    sigset_t set, oset, saveset;

    signal(SIGINT, int_handler);
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigprocmask(SIG_UNBLOCK, &set, &saveset); // 在设置 之前 保存原有的信号集
    sigprocmask(SIG_BLOCK, &set, &oset);
    for(j = 0; j < 1000; j++)
    {
        for(i = 0; i < 5; i++)
        {
            write(1, "*", 1);
            sleep(1);
        }
        write(1,"\n", 1);
        sigsuspend(&oset);
     /*   sigset_t tmpset;
        sigprocmask(SIG_SETMASK, &oset,&tmpset);
        pause();
        sigprocmask(SIG_SETMASK, &tmpset,NULL);*/

    }
     sigprocmask(SIG_SETMASK, &saveset, NULL); // 恢复原有的信号集


    exit(0);
}