/* struct 内存问题及函数传参 */

#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32

struct simp_st
{
    int i;
    char ch;
    float f;
    // char ch1;
};
//}__attribute__((packed));

struct student_st {
    int id;
    char name[NAMESIZE];
    struct birthday_st {
        int year;
        int month;
        int day;
    } birth;
    int math;
    int chinese;
};
void func(struct simp_st b) {
    printf("%d\n", sizeof(b));
}

void funcp(struct simp_st *b) {
    printf("%d\n", sizeof(b));
}

int main() {
    struct simp_st a;
    struct simp_st *p = &a;

/*    printf("sizeof(point) = %d\n",sizeof(p));
    printf("sizeof(struct) = %d\n",sizeof(a));*/
    func(a);
    funcp(p);
    exit(0);
}
