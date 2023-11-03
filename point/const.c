/* const与指针 */

#include <stdio.h>
#include <stdlib.h>

/*
 *  const int a; 常量
 *  int const a; 常量
 *
 *  const int *a;
 *    常量指针：指针的指向可以发生改变，指针所指向的空间的值是不能发生改变的 
 * * int const *a; 常量指针
 *
 *  int *const p;
 *    指针常量：指针的指向不可以发生改变，指针所指向的空间的值是可以发生改变的
 *
 *  const int *const p;  既是常量指针又是指针常量
 * */
// #define 定义常量，但不检查语法
// confst  也是定义常量  会检查语法 比如 const float pi = 3.14;
// 会检查数据类型是不是float
//

#define PI 3.14

int main() {
  int i = 1;
  int j = 100;
  const int *const p = &i; //常量指针和指针常量

  //p = &j ; // 不可以 指针指向不可以改变的
  //*p = 10; // 不可以 指针指向的空间的值也不可以改变的

  printf("%d\n", *p);
#if 0
  int i = 1;
  int j = 100;
  int * const p = &i; //指针常量
  // *p = 10; // 可以 指针指向的变量的值 可以变化
  // p = &j; // 不可以 指针的指向不能改变的。

  printf("%d\n",*p);
#endif
#if 0
    int i = 1;
    int j = 100;
    const int *p = &i;  // 常量指针
    // i = 10; // 可以
    // *p = 10 // 不可以 指针指向的变量不可以改变
    // p = &j;  //可以 指针的指向能改变
    printf("%d\n", *p);
#endif

#if 0
    const float pi = 3.14; // const常量， 一旦定义一定要初始化
    //pi = 3.1415926; //报错
   // float *p = &pi; // 报出警告，
    *p = 3.1415926;// 间接改变了pi的值 emmm 太恶劣了 

    printf("%f\n", pi);
#endif
  exit(0);
}
