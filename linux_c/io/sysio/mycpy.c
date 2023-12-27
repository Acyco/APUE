//
// Created by Acyco on 2023-12-27.
//
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>


#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int sfd, dfd;
    char buf[BUFSIZE];
    int len, ret, pos;

    if(argc < 3)
    {
        fprintf(stderr, "Usage... \n");
        exit(1);
    }
    sfd = open(argv[1], O_RDONLY);
    if(sfd < 0)
    {
        perror("open()");
        exit(1);
    }
    dfd = open(argv[2], O_WRONLY|O_CREAT,O_TRUNC, 0600);
    if(dfd  < 0)
    {
        close(sfd);
        perror("open()");
        exit(1);
    }

    while (1)
    {
        len = read(sfd,buf,BUFSIZE);
        if(len < 0)
        {
            perror("read()");
            break;
        }
        if(len == 0)
            break;


        pos = 0;
        while (len > 0)
        {
            ret = write(dfd,buf+pos,len);
            if(ret < 0)
            {
                perror("write()");
                exit(1);
            }
            pos += ret;
            len -= ret;
        }
    }

    close(dfd);
    close(sfd);
    exit(0);
}