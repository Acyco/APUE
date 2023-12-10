/* 函数指针 */

// 指针函数
//  返回值 * 函数名（形参；
//  如： int * fun(int);
//
// 函数指针
// 类型 （*指针名）（形参）
// 如： int (*p)(int);
//
// 函数指针数组
// 类型 (*数组名【下标】)(形参);
// 如：int (*arr[N])(int)
//
//
// 指向指针函数的函数指针数组
//  int *  (*funcp[N])(int)

#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int main() {

    int a = 3, b = 5;
    int ret;
    int i;
#if 0
    int (*p)(int,int);
    int (*q)(int,int);
    p = add;
    q = sub;

    // ret = add(a, b);
    ret = p(a, b);
    printf("%d\n", ret);

    ret = q(a, b);
    printf("%d\n", ret);

#endif

    int (*funcp[2])(int, int);

    funcp[0] = add;
    funcp[1] = sub;

    for (i = 0; i < 2; i++) {
        ret = funcp[i](a, b);
        printf("%d\n", ret);
    }

    exit(0);
}
