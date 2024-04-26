#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getMaxDepth(char* data,int start,int end){
    int len=strlen(data);
    while(2*end+2<len){
        start=2*start+1;
        end=2*end+2;
    }
    return end-start+1;
}
int main(int argc,char** argv){
    char* data="ABCDEFG";
    printf("最大宽度为: %d\n",getMaxDepth(data,0,0));
    return 0;
}