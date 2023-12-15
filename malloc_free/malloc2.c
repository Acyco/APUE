#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p = NULL;
    p = malloc(sizeof(int));
    if (p == NULL)
    {
        printf("malloc error!\n");
        exit(1);
    }
    *p = 10;

    printf("%p->%d\n",p, *p);

    free(p);
    p = NULL; // 释放内存 马上把指针设置为空 后面继续操作就会报出段错误 不会操作野指针

    *p = 123;
    printf("%p ->%d\n",p, *p);

    exit(0);
}