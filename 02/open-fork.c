#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>


int main(){
    int fd,process;
    // o_WRONLY 以只读打开
    // o_CREAT 当文件不存在时则创建文件
    // o_APPEND 以追加方式写入文件
    fd = open("data.txt",O_WRONLY|O_CREAT|O_APPEND);
    if(fd==-1){
        fprintf(stderr,"open error()");
        exit(1);
    }
    
    process = fork();
    if(process<0){
        fprintf(stderr,"fork() error");
        exit(1);
    } else if(process ==0){
        char buf[200] = "I am Child process\n";
        if(write(fd,buf,strlen(buf)) == -1){
            fprintf(stderr,"write error");
        }
        close(fd);
    } else{
        char buf[200] = "I am parent process\n";
        if(write(fd,buf,strlen(buf)) == -1){
            fprintf(stderr,"write error");
        
         }
        close(fd);
    }

    return 0;
}
