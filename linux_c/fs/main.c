//
// Created by Acyco on 2023-12-28.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;

    printf("argc= %d\n", argc);

//    for (int i = 0; i < argc; ++i)
    for (int i = 0; argv[i] != NULL ; ++i)
        puts(argv[i]);

    exit(0);
}