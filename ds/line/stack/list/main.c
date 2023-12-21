//
// Created by Acyco on 2023-12-22.
//
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

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

    STACK *st;
    struct score_st tmp;
    int i, ret;

    st = stack_create(sizeof(struct score_st));
    if(st == NULL)
        exit(1);

    for(i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"stu%d", i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        if(stack_push(st, &tmp))
            exit(1);
    }


    while (1)
    {
        ret =  stack_pop(st, &tmp);
        if(ret == -1)
            break;
        print_s(&tmp);
    }

    stack_destroy(st);

    exit(0);
}