/*指针变量与变量地址*/
#include <stdio.h>
#include <stdlib.h>


int main ()
{
    int i = 1;
    //int *p;
    //p = &i;
    // 上面两句可以合并为一句
    int *p = &i;

    printf("i = %d\n", i);
    printf("&i = %p\n", &i);
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
//输出类似于这们  p 是等于地址i
// i = 1
// &i = 0x16bd23188
// p = 0x16bd23188
// *p = 1

    exit(0);
}
