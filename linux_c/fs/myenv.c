//
// Created by Acyco on 2023-12-30.
//

#include <stdio.h>
#include <stdlib.h>

extern char ** environ;

int main()
{
    int i;

    for(i = 0; environ[i] != NULL; i++)
        puts(environ[i]);

    exit(0);
}