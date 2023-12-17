//
// Created by Acyco on 2023-12-17.
//
#include <stdio.h>
#include <stdlib.h>
#include "nohead.h"

struct node_st *list_insert(struct node_st *list, struct score_st *data)
{
    struct node_st *new;
    new = malloc(sizeof(*new));
    if (new == NULL)
        return NULL;

    new->data = *data;;
    new->next = list;
    list = new;
    return list;
}

void list_show(struct node_st *list)
{
    struct node_st *cur;
    for (cur = list; cur != NULL; cur = cur->next)
    {
        printf("%d %s %d %d\n", cur->data.id, cur->data.name, cur->data.math, cur->data.chinese);
    }
}
/*
list_delete();
list_find();
*/