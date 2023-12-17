//
// Created by Acyco on 2023-12-17.
//
#include <stdio.h>
#include <stdlib.h>
#include "nohead.h"

int main()
{
    int i;
    struct node_st *list = NULL;
    struct score_st tmp;
    for (i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "stu%d", i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        list = list_insert(list, &tmp);
    }
    list_show(list);

    exit(0);
}