#include <iostream>
using namespace std;

class Vector{
private:
    int *p;    // 指向向量的指针
    int size;  // 向量的总大小
    int n;     // 向量的实际大小
public:
    Vector(int size=100){
        p = (int*)malloc(100*sizeof(int));
        n=0;
        this->size = size;
    }

    // 返回向量的实际大小
    int getSize(){
        return n;
    }

    //判断向量是否为空
    bool isEmpty(){
        return (n==0)?true:false;
    }

    // 取特定下标的元素
    int getElement(int r){
        if(r>=size || r<0){
            cout<<"下标越界或下标为负"<<endl;
            exit(-1);    // 退出进程
        }else{
            return p[r];
        }
    }

    // 修改特定下标位置的元素，返回修改之前元素的值
    int editElement(int r,int tem){
        if (r >= size || r < 0){
            cout << "下标越界或下标为负" << endl;
            exit(-1); // 退出进程
        } else {
            int bak = p[r];
            p[r] = tem;
            return bak;
        }
    }

    // 在特定下标位置插入元素
    int insert(int r,int tem){
        if(n+1>size){ // 如果空间不足，分配更大的空间
            p = (int*)realloc(p,2*size);
            size = 2*size;
        }

        if(r>=n || r<0){     // 如果 r 大于等于元素的个数 或 r为负数，则将其插入向量的末尾
            p[n] = tem;
            n++;
        }else{
            for(int i=n;i>r;i--){
                p[n] = p[n-1];
            }
            n++;
            p[r]=tem;
            return tem;
        }
        return -1;
    }

    // 删除特定位置的元素
    int deletElement(int r){
        if(r<0 || r>=n){
            printf("下标越界或为负");
            exit(-1);
        }
        int bak = p[r];
        for(int i=r;i<n;i++){
            p[i] = p[i+1];
        }
        n--;
        return bak;
    }

    // 释放内存
    ~Vector(){
        free(p);
    }


};

int main(){
    Vector vec(200);
    cout << "元素个数: " << vec.getSize() << endl;
    cout << "是否为空: " << vec.isEmpty() << endl;

    vec.insert(-1,123);    // 在末尾添加元素
    vec.insert(0,124);     // 在下标 0 添加元素
    cout << "vec[0] = " << vec.getElement(0) << endl;   // 获取 vec[0]
    cout << "vec[1] = " << vec.getElement(1) << endl;   // 获取 vec[1]

    cout << "元素个数: " << vec.getSize() << endl;
    cout << "是否为空: " << vec.isEmpty() << endl;

    vec.editElement(0,1024);
    cout << "vec[0] = " << vec.getElement(0) << endl; // 获取 vec[0]

    vec.deletElement(0);
    cout << "元素个数: " << vec.getSize() << endl;
    cout << "vec[0] = " << vec.getElement(0) << endl; // 获取 vec[0]

    return 0;
}