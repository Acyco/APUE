//
// Created by Acyco on 2023-12-15.
//
#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

sqlist *sqlist_create()
{
    sqlist *me;
    me = malloc(sizeof(*me));
    if (me == NULL)
        return NULL;
    me->last = -1;
    return me;
}

void sqlist_create1(sqlist **ptr)
{
    *ptr = malloc(sizeof(**ptr));
    if (*ptr == NULL)
        return;
    (*ptr)->last = -1;
    return;
}

int sqlist_insert(sqlist *me, int i, datatype *data)
{
    int j;
    if (me->last == DATASIZE - 1)
        return -1;
    if (i < 0 || i > me->last + 1)
        return -2;

    for (j = me->last; i <= j; j--)
        me->data[j + 1] = me->data[j];

    me->data[i] = *data; // 限制基础类型才这样做 复杂数据结构用memcpy
    me->last++;

    return 0;

}

int sqlist_delete(sqlist *me, int i)
{
// i --> 删除指定下标的数据
    int j;
    if (i < 0 || i > me->last)
        return -1;

    for (j = i + 1; j <= me->last; j++) // i=1 j = 2
        me->data[j - 1] = me->data[j];
    me->last--;
    return 0;

}

int sqlist_find(sqlist *me, datatype *data)
{
    int i;
    if (sqlist_isempty(me) == 0)
        return -1; // 空 没有数据
    for (i = 0; i < me->last; i++)
        if (me->data[i] == *data)
            return i; // 返回下标
    return -2; // 找不到
}

int sqlist_isempty(sqlist *me)
{
    if (me->last == -1)
        return 0;
    return -1;
}

int sqlist_setempty(sqlist *me)
{
    me->last = -1;
    return 0;
}

int sqlist_getnum(sqlist *me)
{
    return me->last + 1;
}

void sqlist_display(sqlist *me)
{

    int i;
    if (me->last == -1)
        return;
    for (i = 0; i <= me->last; i++)
        printf("%d ", me->data[i]);

    printf("\n");

}

int sqlist_destroy(sqlist *me)
{
    free(me);
    return 0;
}

int sqlist_union(sqlist *list1, sqlist *list2)
{
    // list1 -> 12 23 34 45 56
    // list2 -> 78 89 56 23 10    // 78 89 10
    // list1 为合并目标
    int i;
    for (i = 0;i <= list2->last; i++)
    {
        if(sqlist_find(list1,&list2->data[i]) < 0) // <0 代表没有找到
        {
            sqlist_insert(list1,0, &list2->data[i]);
        }
    }


}