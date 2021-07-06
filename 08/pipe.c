#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

#define BUF_SIZE 30

int main(){
    int fds[2];
    char str[] = "Hello world";
    char buf[BUF_SIZE];
    pid_t pid;

    pipe(fds);    // 创建管道，此时 fds[0] 用于读取，fds[1] 用于写入数据
    pid = fork();
    if(pid == 0 ){
        write(fds[1],str, sizeof(str));  
        // 向缓冲区中写入数据

    }else{
        read(fds[0],buf,BUF_SIZE); 
        // 如果父进程在子进程写入之前尝试读取，则会阻塞，直到管道内出现数据
        // read 返回负数，说明读取过程中发生错误，返回大于 0 的数，表示实际读取的字符
        // 等于 0 表示到达文件末尾
        puts(buf);
    }
    return 0;
}
