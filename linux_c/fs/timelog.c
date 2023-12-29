//
// Created by Acyco on 2023-12-30.
//
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

#define FNAME "/tmp/out"
#define BUFSIZE 1024

int main()
{
    struct tm *tm;
    FILE  *fp;
    int count;
    char buf[BUFSIZE];
    time_t stamp;

    fp = fopen(FNAME,"a+");
    if(fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    while(fgets(buf,BUFSIZE,fp) != NULL)
        count++;

    while(1)
    {
        time(&stamp);
        tm = localtime(&stamp);
        fprintf(fp, "%-4d%d-%d-%d %d:%d:%d\n", ++count, tm->tm_year+1900,
        tm->tm_mon+1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
        sleep(1);
        fflush(fp);
    }

    fclose(fp);

    exit(0);
}