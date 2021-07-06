#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// 演示 int execvp(const char * file，char * const argv[])；
// file 表示可执行文件名字
// argv 表示参数列表，该数组最后一个元素必须是 NULL
int main(){
    pid_t pid;

    pid = fork();
    if(pid<0){
        fprintf(stderr,"fork() error");
        exit(1);
    }else if(pid == 0){
       char * argv[] = {"ls", "-al", NULL};
       execvp("ls",argv);
    } else{
        wait(NULL);
    }
    

    return 0;
}
