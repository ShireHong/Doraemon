#include <sys/socket.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include<sys/types.h>
#include<sys/uio.h>
#include<stddef.h>
static const int CONTROL_LEN = CMSG_LEN(sizeof(int));

/*发送文件描述符 fd参数是用来传递信息的UNIX域socket， 
*fd_to_send参数是待发送的文件描述符    
**/
void send_fd(int fd, int fd_to_send)
{
    struct iovec iov[1];
    struct msghdr msg;
    char buf[0];

    iov[0].iov_base = buf;
    iov[0].iov_len = 1;
    msg.msg_name = NULL;
    msg.msg_namelen = 0;
    msg.msg_iov = iov;
    msg.msg_iovlen = 1;

    struct cmsghdr cm;
    cm.cmsg_len = CONTROL_LEN;
    cm.cmsg_level = SOL_SOCKET;
    cm.cmsg_type = SCM_RIGHTS;
    *(int*)CMSG_DATA(&cm) = fd_to_send;
    msg.msg_control = &cm; /*设置辅助数据*/
    msg.msg_controllen = CONTROL_LEN;

    sendmsg(fd, &msg, 0);
}

/*接收文件描述符*/
int recv_fd(int fd)
{
    struct iovec iov[1];
    struct msghdr msg;
    char buf[0];

    iov[0].iov_base = buf;
    iov[0].iov_len = 1;
    msg.msg_name = NULL;
    msg.msg_namelen = 0;
    msg.msg_iov = iov;
    msg.msg_iovlen = 1;

    struct cmsghdr cm;
    msg.msg_control = &cm;
    msg.msg_controllen = CONTROL_LEN;

    recvmsg(fd, &msg, 0);

    int fd_to_read = *(int*)CMSG_DATA(&cm);

    return fd_to_read;
}

int main(int argc, char* argv[])
{
    int pipefd[2];
    int fd_to_pass = 0,x=0;
    /*创建父子进程管道*/
    int ret = socketpair(PF_UNIX, SOCK_DGRAM, 0, pipefd);
    assert(ret != -1);
	//pipe(pipefd);
    pid_t pid = fork();
    if(pid == 0)
    {
        close(pipefd[0]);
        fd_to_pass = open("data.txt", O_RDWR, 0666);
		x=fd_to_pass;
        /*子进程通过管道将文件描述符发送到父进程。
        如果文件test.txt打开失败，则子进程将标准输入文件描述符(0)发送到父进程。
        */
		write(fd_to_pass,"loser",5);
        send_fd(pipefd[1], (fd_to_pass > 0) ? fd_to_pass : 0);
        close(fd_to_pass);
	//	close(pipefd[1]);
        exit(0);
    }else{
	//wait(NULL);
    close(pipefd[1]);
    fd_to_pass = recv_fd(pipefd[0]);
    char buf[1024];
    memset(buf, '\0', 1024);
    read(fd_to_pass, buf, 1024);
	write(fd_to_pass,buf,1024);
    printf("I got fd %d and data %s\n", fd_to_pass, buf);
	printf("%d\n",x);
	//close(pipefd[0]);
    close(fd_to_pass);
	}
    return 0;
}
