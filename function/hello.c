/* 声明与定义 */

#include <stdio.h>

void print_hello(void); // 函数声明

int main(void) {
  print_hello(); // 在main函数要调用的函数，必须在main函数前先声明，不过现在不声明，编译器也会给你做链接上,但依旧还会报警告
  return 0;
}

void print_hello(void) // 函数定义
{
  printf("Hello world!\n");
}
