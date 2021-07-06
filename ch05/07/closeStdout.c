#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
    pid_t pid;
    pid = fork();
    // 除了子进程区域和父进程区域
    if(pid<0){
        fprintf(stderr,"fork() error");
        exit(1);
    }else if(pid==0){
        // 子进程区域
        close(STDOUT_FILENO);
        open("tem.txt",O_CREAT| O_WRONLY,S_IRWXU);
        printf("Hello world\n");
    }else{
        // 父进程区域
        printf("parent pid: %d\n",(int)getpid());
    }
    return 0;
}
