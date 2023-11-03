/* 二级指针 v07.03*/
#include <stdio.h>
#include <stdlib.h>


int main ()
{
    int i = 1;
    int *p = &i; // 定义一个一级指针
    int **q = &p; //定义一个二级指针 

// i的取值：     i   *p  **q
// i的地址:     &i    p   *q

    printf("i = %d\n", i);
    printf("&i = %p\n", &i);
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
    printf("q = %p\n", q);
    printf("*q = %p\n", *q);
    printf("**q = %d\n", **q);
/*  打印出类似这样 
i = 1
&i = 0x16fb33188
p = 0x16fb33188
*p = 1
q = 0x16fb33180
*q = 0x16fb33188
**q = 1

*/
    exit(0);
}
