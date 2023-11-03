/* 指针数组与数组指针 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  数组指针： 【存储类型】 数据类型 （*指针名） 【下标】 = 值
 *  int (*p)[3]; -> type name; -> int[3]  *p
 *  指针数组： 【存储类型】 数据类型 * 数组名 【长度】
 *  int * arr[3]; -> type name; -> int *[3] arr;
 * */

int main() {
  char *name[5] = {"Follow me", "Basic", "Great", "Acyco", "Computer"};
  int i, j, k;
  char *tmp;

  for (i = 0; i < 5 - 1; i++) {
    k = i;
    for (j = i + 1; j < 5; j++) {

      if (strcmp(name[k], name[j]) >0) {
        k = j;
      }
    }
    if (k != i) {
      tmp = name[i];
      name[i] = name[k];
      name[k] = tmp;
    }
  }

  for (i = 0; i < 5; i++) {
    puts(name[i]);
  }

  exit(0);
}
