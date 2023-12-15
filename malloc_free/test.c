#include <stdio.h>
#include <stdlib.h>

#if 0
void func( int **p, int n)
{
    *p = malloc(n);
    if(*p == NULL)
        exit(1);
    return;
}
#endif

int *func(int *p, int n)
{
    p = malloc(n);
    if (p == NULL)
        exit(1);
    return p;
}

int main()
{
    int num = 100;
    int *p = NULL;
    // func(&p, num); // 二级指针

    p = func(p, num);

    free(p);
    exit(0);
}