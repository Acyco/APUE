/* 二维数组与指针 v07.06 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a[2][3] = {1, 2, 3, 4, 5, 6};
  int i, j;
  // int *p = a; //会报警告 指针类型不兼容 如果这样，指针p则是在列上移动 而a 则是行移动 
  int *p = &a[0][0]; // 也可以*a, *a 相当于*(a+0)

  for (i = 0 ; i<6; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");


#if 0
  printf("%p %p\n", a, a+1);// a + 1 是指向4的地址
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("%p ---> %d\n", &a[i][j], a[i][j]);
    }
    printf("\n");
  }
  // 1 2 3
  // 4 5 6
#endif

  exit(0);
}
