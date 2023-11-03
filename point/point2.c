/* 空指针 野指针 及void指针  v07.03  */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = NULL; //空指针
    void *q; // 这是一个百搭的指针，什么类型的指针都可以赋值给它。它可以转变为各种类型指针。

    // 设置成空指针，如果去使用这个指针就会报出段错误             
    printf("%p ----> %d\n", p, *p);

#if 0
    int *p;
    // 会造成野指针,有的运行时，是可以通过，有的则会报段错误， 看编译器怎么处理的
    printf("%p ----> %d\n", p, *p);
#endif
    exit(0);
}
