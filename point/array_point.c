/* 数组指针 */

#include <stdio.h>
#include <stdlib.h>

// 数据指针： 【存储类型】 数据类型 （*指针名）【下标】 = 值
// 如： int (*p)[3] ;  => type name -> int [3] *p;

int main()
{
  int a[2][3] = {1, 2, 3, 4, 5, 6};
  int i, j;
  int *p = *a; //
  int (*q)[3] = a; //数组指针

  printf("%p %p\n", a, a+1);
  printf("%p %p\n", q, q+1);

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("%p ---> %d\n", *(q+i)+j, *(*(q+i))+j);
    }
    printf("\n");
  }

  exit(0);
 
}

