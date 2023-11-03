/* 指针运算级优先级 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a[] = {5, 1, 7, 2, 8, 3};
    int y;
    int *p = &a[1];

    y = (*--p)++; // y=5 , --p 相当于p指向a[0] 后累加 这里的优先级是 先赋值 再累加的  也就是先把y赋值为5 再改变a[0] 

    printf("y = %d\n", y); //y = 5
    printf("a[0] = %d\n", a[0]); // a[0] = 6

    exit(0);

}
