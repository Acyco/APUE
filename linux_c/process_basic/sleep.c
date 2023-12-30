//
// Created by Acyco on 2023-12-30.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;

    puts("Begin!");

    fflush(NULL);

    pid = fork();
    if(pid < 0)
    {
        perror("fork()");
        exit(1);
    }

    if(pid == 0)
    {
        execl("/bin/sleep", "httpd", "100", NULL);
        perror("execl()");
        exit(1);
    }

    wait(NULL);

    puts("End!");

    exit(0);
}