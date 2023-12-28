//
// Created by Acyco on 2023-12-28.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;

    if(argc < 0)
    {
        fprintf(stderr,"Usage....\n");
        exit(1);
    }

    fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if(fd < 0)
    {
        perror("open()");
        exit(1);
    }

    lseek(fd, 5L * 1024L * 1024L* 1024L - 1L, SEEK_SET);

    write(fd, "", 1);

    close(fd);

    exit(0);
}