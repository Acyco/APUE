/* struct */

#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32

struct simp_st {
    //int i, j;
    int i;
    float f;
    char ch;
};

/* 
struct birthday_st {
    int year;
    int month;
    int day;
};
*/

struct student_st {
    int id;
    char name[NAMESIZE];
    // int year, nonth, day;
    struct birthday_st {
        int year;
        int month;
        int day;
    } birth;
    int math;
    int chinese;
};

int main() {
    struct simp_st a = {123, 456.789, 'a'};
    a.i = 112233;
    printf("%d %f %c\n", a.i, a.f, a.ch);

    exit(0);
}
