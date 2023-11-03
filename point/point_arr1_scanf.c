/* 指针数组 */

#include <stdio.h>
#include <stdlib.h>

// TYPE NAME = VALUE;

// a[i]:  a[i] = *(a+i) = *(p+i) = p[i]
// &a[i]: &a[i] = a+i = p+i = &p[i]

int main() {
  int a[3]; // int[3] 是类型
  int i;
  int *p = a; // 定义指针p 指向数组a
  for (i = 0; i < sizeof(a) / sizeof(*a); i++) {
    printf("%p ---> %d\n", &a[i], a[i]);
  }

  for (i = 0; i < sizeof(a) / sizeof(*a); i++) {
    scanf("%d", p++);
  }

  p = a; //如果不重新把p 重定向到a  p指针就越界了

  for (i = 0; i < sizeof(a) / sizeof(*a); i++) {
    printf("%p --> %d\n", p, *(p++));
  }
  exit(0);
}
