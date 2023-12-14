/* struct */

#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32

struct simp_st {
    int i;
    float f;
    char ch;
};

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

int main() {
    /**
    struct simp_st a = {123, 456.789, 'a'};
    a.i = 112233;
    printf("%d %f %c\n", a.i, a.f, a.ch);
    */
    int i;

    struct student_st stu = {100011,"Alen",{2011,11,11}, 98, 97};
    struct student_st *p = &stu;
    struct student_st arr[2] = {
        {100011,"Alen",{2011,11,11}, 98, 97},
        {100012,"John",{2012,12,12}, 90, 80}
    };
    // struct student_st stu = {.math=98, .chinese=97};


    printf("%d %s %d-%d-%d %d %d\n",stu.id, stu.name, stu.birth.year, stu.birth.month, stu.birth.day, stu.math, stu.chinese);
    printf("%d %s %d-%d-%d %d %d\n",p->id,p->name, p->birth.year, p->birth.month, p->birth.day, p->math, p->chinese);

    p = &arr[0];
    for (i = 0; i < 2; i++,p++) {
        printf("%d %s %d-%d-%d %d %d\n",p->id,p->name, p->birth.year, p->birth.month, p->birth.day, p->math, p->chinese);
    }

    exit(0);
}
