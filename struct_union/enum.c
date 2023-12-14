#include <stdio.h>
#include <stdlib.h>

enum day {
    MON = 1,
    TUS,
    THR,
    WES,
    FRI,
    SAT,
    SUN
};

enum
{
    STATE_RUNNING = 1,
    STATE_CANCELED,
    STATE_OVER
};

struct job_st
{
    int id;
    int state;
    int start, end;
};

int main(){

    struct job_st job1;
//    job1.state = 1;

    switch (job1.state)
    {
        case STATE_RUNNING:
            break;
        case STATE_CANCELED:
            break;
        case STATE_OVER:
            break;
        default:
            abort();
    }

    /*
    enum day a = FRI;

    printf("%d\n", a);
     */
    exit(0);
}
