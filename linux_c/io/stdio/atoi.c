//
// Created by Acyco on 2023-12-26.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{

    char buf[1024];
    int year = 2023, month = 12, day = 26;
    sprintf(buf, "%d-%d-%d", year, month, day);
    puts(buf);


//    char str[] = "123a456";
//    printf("%d\n", atoi(str));

    exit(0);
}