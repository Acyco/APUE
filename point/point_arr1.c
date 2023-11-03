/* 指针数组 */

#include <stdio.h>
#include <stdlib.h>

// TYPE NAME = VALUE;

// a[i]:  a[i] = *(a+i) = *(p+i) = p[i]
// &a[i]: &a[i] = a+i = p+i = &p[i]

int main() {
  int a[3] = {1, 2, 3}; // int[3] 是类型
  int i;
  int *p = a; // 定义指针p 指向数组a

  // 下面打印都一样，但两者的区别是 a 是常量，意味a是不可变，
  // p指针是变量，是可以随意改变，随意指向
  printf("%p, %p\n", a, a + 1);
  printf("%p, %p \n", p, p + 1);

  // p进行累加操作
  p++;
  printf("%p, %p\n", a, a + 1);
  printf("%p, %p \n", p, p + 1);// 上面的p++ 所以p的指向的地址已经改变了 因此p+1所指向的地址不会和a+1所指向的地址相同

  p = a; // 再次重置指向地址，指向a的地址
  // for (i=0; i<sizeof(a)/sizeof(a[0]); i++) {
  for (i = 0; i < sizeof(a) / sizeof(*a); i++) { // *a  = *(a+0)  = a[0]  效果是一样的， 但我不现在不清楚二维数组是不是同样 

    // printf("%p --> %d\n", &a[i], a[i]);
    // printf("%p --> %d\n", a+i, a[i]);
    // printf("%p --> %d\n", p+i, a[i]);
    printf("%p --> %d\n", p + i, *(p + i));
  }
  printf("\n");

  exit(0);
}
