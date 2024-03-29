//
// Created by Acyco on 2023-12-30.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

#define FNAME   "/tmp/out"

int daemonize()
{
    pid_t pid;
    int fd;

    pid = fork();
    if(pid < 0)
        return -1;


    if(pid > 0) // parent
        exit(0);

    fd = open("/dev/null", O_RDWR);
    if(fd < 0)
        return -1;

    dup2(fd, 0);
    dup2(fd, 1);
    dup2(fd, 2);

    if(fd > 2)
        close(fd);

    setsid();

    chdir("/");
    // umask;
    return 0;
}

int main()
{
    FILE  *fp;
    int i;

    openlog("mydaemon", LOG_PID,LOG_DAEMON);

    if(daemonize())
    {
        syslog(LOG_ERR, "daemonize() failed!" );
        exit(1);
    }
    else
    {
        syslog(LOG_INFO, "daemonize() successded!");
    }

    fp = fopen(FNAME, "w");
    if(fp == NULL)
    {
        syslog(LOG_ERR,"fopen():%s", strerror(errno));
        exit(1);
    }

    syslog(LOG_INFO,"%s was opened.", FNAME);

    for(i = 0; ; i++)
    {
        fprintf(fp, "%d\n", i);
        fflush(fp);
        syslog(LOG_DEBUG, "%d is printed.", i);
        sleep(1);
    }

    closelog();
    fclose(fp);

    exit(0);
}