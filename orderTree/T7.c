// 求解第k层的节点数
#include<stdio.h>
#include<stdlib.h>
int getNode(char* data,int start,int end,int k){
    int count=1;
    while(count!=k){
        start=2*start+1;
        end=2*end+2;
        count++;
    }
    return end-start+1;
}
int main(){
    char* data="ABCDEFG";
    printf("请输入层数:\n");
    int k;
    scanf("%d",&k);
    printf("第%d层的节点个数为%d\n",k,getNode(data,0,0,k));
}