#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(){
    pid_t pid;
    pid = fork();
    int x = 100;
    printf("main x=%d\n",x);
    // 除了子进程区域和父进程区域
    if(pid<0){
        fprintf(stderr,"fork() error");
        exit(1);
    }else if(pid==0){
        // 子进程区域
      	x++;
        printf("child process x=%d\n",x);
    }else{
        // 父进程区域
      	x++;
        printf("parent process x=%d\n",x);
    }
    return 0;
}
