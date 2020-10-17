#ifndef  _COMM_API_H
#define  _COMM_API_H

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>


#define SERV_PORT 9300
#define SA struct sockaddr

ssize_t new_read(int fd,char *ptr);

ssize_t writen(int fd,void *buf,size_t n);
ssize_t read_line(int fd,void* buf,size_t maxline);

#endif



