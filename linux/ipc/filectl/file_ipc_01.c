#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char** argv){
    pid_t pid;
    int fd = open("data.dat", O_RDWR|O_TRUNC|O_CREAT, 0644);
    if(fd == -1){
        printf("open fails\n");
        exit(1);
    }
    char buf[] = "databuffer\n\0";
    if((pid = fork()) < 0){
        printf("fork error\n");
        return -1;
    }else if(pid == 0){
        write(fd, buf, strlen(buf));
        fsync(fd);
        close(fd);
        exit(0);
    }

 //   sleep(1); 
	/*char str[100];
      printf("%d\n",fd);
      memset(str, 0, 100);
   lseek(fd, 0, SEEK_SET);
      int n=read(fd, str, 100);
      close(fd);
      printf("%s    %d\n", str,n);*/
wait(NULL);
    memset(buf, 0, sizeof(buf)/sizeof(char));
    lseek(fd, 0, SEEK_SET);
    read(fd, buf, sizeof(buf));
    printf("%s\n", buf);
    return 0;
}

