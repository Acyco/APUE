//
// Created by Acyco on 2023-12-26.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE  *fp;
    char *linebuf;
    size_t linesize; // 一定要进行初始化

    if(argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    /*!!!!!!!!*/
    linebuf = NULL;
    linesize = 0;

    while (1)
    {
       if(getline(&linebuf, &linesize, fp) <0)
           break;
        printf("%lu\n", strlen(linebuf)); // macos %d --> %lu
        printf("%zu\n",linesize);  // macos %d --> %zu
    }

    fclose(fp);

    exit(0);
}