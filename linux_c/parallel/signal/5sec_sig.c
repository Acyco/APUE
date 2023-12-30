//
// Created by Acyco on 2023-12-31.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static volatile int loop = 1;

static void alrm_handler(int s)
{
    loop = 0;
}


int main()
{
    int64_t count = 0;


    // 这个信号处理 最好一定要放在alarm之前，因为你放在之后 alarm后面处理大量时间时，时间一到没有对应的信号处理
    //
    signal(SIGALRM, alrm_handler);
    alarm(5);

    while (loop)
        count++;

    printf("%lld\n", count);

    exit(0);
}