#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 交换子节点
void swapTree(char* data,int start,int end);
void mirrorTree(char* data,int start,int end);
void mirrorTree(char* data,int start,int end){
    // 交换start和end之间的元素
    int len=strlen(data);
    if(end>=len){
        return ;
    }
    // 开始交换
    swapTree(data,start,end);
    // 开始交换之后区间的
    mirrorTree(data,2*start+1,2*end+2);
}
// 交换一个区间里面的元素
void swapTree(char* data,int start,int end){
    for(int i=start,j=end;i<=j;i++,j--){
        char temp=data[i];
        data[i]=data[j];
        data[j]=temp;
    }
}
int main(int argc,char** argv){
    char* data=argv[1];
    printf("交换之前的二叉树为: %s\n",data);
    mirrorTree(data,0,0);
    printf("之后的二叉树为: %s\n",data);
}
