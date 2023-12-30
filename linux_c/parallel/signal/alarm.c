//
// Created by Acyco on 2023-12-31.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    alarm(10);
    alarm(5);
    alarm(1);


    while (1)
        pause();


    exit(0);
}