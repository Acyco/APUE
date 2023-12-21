//
// Created by Acyco on 2023-12-22.
//
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    queue *sq;
    datatype arr[] = {2, 34, 98, 12};
    int i, ret;

    sq = qu_create();
    if (sq == NULL)
        exit(1);

    for (i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        qu_enqueue(sq, &arr[i]);

    qu_travel(sq);
/*
    datatype tmp = 100;
    ret = qu_enqueue(sq, &tmp);
    if(ret == -1)
        printf("queue is full!\n");
    else
        qu_travel(sq);
*/

    datatype tmp;
    qu_dequeue(sq, &tmp);
    printf("DEQUEUE: %d\n", tmp);
    qu_travel(sq);

    qu_destroy(sq);
    exit(0);
}