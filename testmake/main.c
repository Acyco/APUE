#include <stdio.h>
#include <stdlib.h>
#include "tool1.h"
#include "tool2.h"

int main()
{
    mytool1();
    mytool2();
    exit(0);
}

/*
 a.out -> main.o tool1.o tool2.o
 main.o -> main.c
 tool1.o -> tool1.c
 tool2.o -> tool2.c
*/