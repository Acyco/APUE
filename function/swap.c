/* 函数的传参 值传参和地址传参 */

#include <stdio.h>
#include <stdlib.h>

#if 0
int printf_value(int i, int j) // i 和j 形式参数  此i非main函数的i j也非main函数的j
{
  printf("%d %d\n", i, j);
  return 0;
}
#endif

#if 0
void swap(int i, int j) // 这里的交换只在swap函数i和j变量  
{
    int tmp;
    tmp = i;
    j = i;
    i = tmp;
}
#endif

void swapp(int *p, int *q) // 地址传参
{
  int tmp;
  tmp = *p;
  *p = *q;  // 通过指针地址间接改变main函数的i变量的值
  *q = tmp; // 通过指针地址间接改变main函数的j变量的值
}

int main() {
  int i = 3, j = 5;

  // printf_value(i, j);//实际参数

  // swap(i, j); // 值传参 不起作用

  swapp(&i, &j); // 

  printf("i = %d\nj = %d\n", i, j);

  exit(0);
}
