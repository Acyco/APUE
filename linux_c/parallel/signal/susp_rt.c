//
// Created by Acyco on 2023-12-31.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define MYRTSIG (SIGRTMIN+6)

static void mysig_handler(int s)
{
    write(1,"!", 1);
}

int main()
{
    int i, j ;
    sigset_t set, oset, saveset;

    signal(MYRTSIG, mysig_handler);
    sigemptyset(&set);
    sigaddset(&set, MYRTSIG);
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

    }
     sigprocmask(SIG_SETMASK, &saveset, NULL); // 恢复原有的信号集


    exit(0);
}