// 找到叶子节点的个数
#include<stdio.h>
#include<stdlib.h>
int findLeavesNum(char* data);
int findLeavesNum(char* data){
    int i=0;
    int count=0;
    while(data[i]!='\0'){
        if(data[i]=='#'){
            count++;
        }
            i++;
    }
    return count;
}
int main(){
    char* data="ABC#EF#";
    printf("叶子节点的个数为: %d\n",findLeavesNum(data));
}