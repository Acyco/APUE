//
// Created by Acyco on 2023-12-27.
//
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FNAME "/tmp/out"

int main()
{
    int fd;

  //  close(1);
    fd  = open(FNAME,O_WRONLY|O_CREAT|O_TRUNC,0600);

    if(fd < 0)
    {
        perror("open()");
        exit(1);
    }

//    close(1); // 后面关闭
//    dup(fd);  // 重新定向到1  如果本来fd 就在1 那么上面close 把关闭了。报错了。。
    dup2(fd, 1); // 上面的两步的原子操作

    if(fd != 1)
    {
        close(fd);
    }

    /*********************************/
    puts("hello!");
    exit(0);
}