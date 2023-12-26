//
// Created by Acyco on 2023-12-26.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE *fp;

    fp = fopen("tmp", "r");
    if(fp == NULL)
    {
        // errno linux:  (*__errno_location ());
        // errno macos:  (*__error());
//        fprintf(stderr, "fopen(): failed! errno = %d\n", errno);
//        perror("fopen()");
        fprintf(stderr, "fopen():%s\n", strerror(errno));
        exit(1);
    }
    puts("OK!");

    fclose(fp);

    exit(0);
}