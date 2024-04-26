#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 求解二叉树的深度
int getDepth(char* data,int end);
int getDepth(char* data,int end){
    int count=0;
    int len=strlen(data);
    // 0 2 6
    while(end<len){
        end=2*end+2;
        count++;
    }
    return count;
}
int main(int argc,char** argv){
    char* data=argv[1];
    int depth=getDepth(data,0);
    printf("树的深度为: %d\n",depth);
    return 0;

}