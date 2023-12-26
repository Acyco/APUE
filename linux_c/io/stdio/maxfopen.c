//
// Created by Acyco on 2023-12-26.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    int count = 0;
    FILE *fp;

    while (1)
    {
        fp = fopen("tmp", "r");
        if(fp == NULL)
        {
            perror("fopen()");
            break;
        }
        count++;
    }

    printf("count = %d\n", count); // iterm2 256: clion: 10240 有三个标准



    exit(0);
}