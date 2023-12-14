#include <stdio.h>
#include <stdlib.h>
union test_un
{
    int i;
    float f;
//    double d;
    char ch;
};

int main ()
{
    union test_un a;
    union test_un *p = &a;
    union test_un arr[3];


//    a.f = 345.678; // 成员引用： 变量名.成员名
    p->f = 345.678; // 指针名->成员名

    printf("%d\n", sizeof(a)); // 8
//    printf("%f\n", a.f);
//    printf("%f\n", a.i);
    printf("%f\n", a.f);
    printf("%f\n", p->f);

    exit(0);
}