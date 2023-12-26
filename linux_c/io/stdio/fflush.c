//
// Created by Acyco on 2023-12-26.
//

#include <stdio.h>
#include <stdlib.h>
/*
 * 缓冲区的作用： 大多数情况下是好事， 合并系统调用
 *
 * 行缓冲： 换行时候刷新，满了的时候刷新，强制刷新（标准输出是这样的，因为是终端设备）
 *
 * 全缓冲： 满了的时候刷新，强制刷新（默认，只厅不是终端设备）
 *
 * 无缓冲： 如stderr, 需要立即输出的内容
 */

int main()
{
    int i;
    printf("Before while");
    fflush(stdout);
//    fflush(NULL);
    while (1);

    printf("After while");
    fflush(NULL);

    exit(0);
}