//
// Created by Acyco on 2023-12-22.
//
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


#define NAMESIZE 32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

void print_s(struct score_st *d)
{
    printf("%d %s %d %d \n",d->id,d->name,d->math,d->chinese);
}

int main()
{
    QUEUE *qu;
    struct score_st tmp;
    int i, ret;

    qu = queue_create(sizeof(struct score_st));
    if(qu == NULL)
        exit(1);

    for(i = 0; i < 6; i++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"stu%d", i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        if(queue_en(qu, &tmp) != 0)
            break;
    }

    while (1)
    {
        ret = queue_de(qu, &tmp);
        if(ret == -1)
            break;
        else
            print_s(&tmp);
    }

    queue_destroy(qu);

    exit(0);
}