//
// Created by Acyco on 2023-12-27.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    putchar('a');
    write(1,"b",1);

    putchar('a');
    write(1,"b",1);

    putchar('a');
    write(1,"b",1);

    // 最后输出的是 bbbaaa
    exit(0);
}