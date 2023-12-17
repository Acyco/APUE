//
// Created by Acyco on 2023-12-17.
//
#include <stdio.h>
#include <stdlib.h>
#include "nohead.h"

int main()
{
    int i, ret;
    struct node_st *list = NULL;
    struct score_st tmp;
    for (i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "stu%d", i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        ret = list_insert(&list, &tmp);
        if (ret != 0)
            exit(1);
    }
    list_show(list);

    printf("\n\n");

    int id = 3;
    struct score_st *ptr;
    ptr = list_find(list, id);
    if (ptr == NULL)
        exit(1);
    else
        printf("%d %s %d %d\n", ptr->id, ptr->name, ptr->math, ptr->chinese);

//    list_delete(&list);
//    list_show(list);

    list_destroy(list);

    exit(0);
}