#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// 演示 int execvp(const char * file，char * const argv[])；
// file 表示可执行文件名字,这里使用 strdup() 构建，该函数将使用 malloc 创建动态内存
// argv 表示参数列表，该数组最后一个元素必须是 NULL，表示参数结束，同上，使用 strdup()
int main(){
    pid_t pid;

    pid = fork();
    if(pid<0){
        fprintf(stderr,"fork() error");
        exit(1);
    }else if(pid == 0){
       char *myargs[2];
       myargs[0] = strdup("ls");
       myargs[1] = NULL;
       execvp(myargs[0],myargs);
    } else{
        wait(NULL);
    }
    

    return 0;
}
