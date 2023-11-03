/* 指针占用字节  v07.03*/
#include <stdio.h>
#include <stdlib.h>


int main ()
{
    int i = 1;
    int *p;
    float *q;
    double *d;
    char *c;

    p = &i;
// 指针的大小是一样 我现在用的操作系统是64位的， 指针占用8个字节, 
// 不同类型的指针，在做运算是不同的
    printf("%ld\n", sizeof(p));
    printf("%ld\n", sizeof(q));
    printf("%ld\n", sizeof(d));
    printf("%ld\n", sizeof(c));

    exit(0);
}
