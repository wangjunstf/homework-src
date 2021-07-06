#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
    int fd;
    
    fd = fork();
    if(fd<0){
        fprintf(stderr,"fork() error");
        exit(1);
    } else if(fd==0){
        printf("child pid = %d\n",(int)getpid());
    } else{
        int status;
        int mywait;
        // 空循环体的无限循环，等待子进程结束
        // status 用于判断子进程是否正常终止 
        // WNOHANG 表示即使没有子进程终止，也不阻塞，不过放在这里，它会一直循环，直到有子进程终止
        while(!(mywait=waitpid(fd,&status,WNOHANG))); 
        printf("waitpid return %d\n",mywait);


    }

    return 0;
}
