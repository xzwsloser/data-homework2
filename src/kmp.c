#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void getNext(char* data,int next[]){
    // 用于求解Next数组
    int i=0; // 主串起始
    next[0]=0;
    int j=1;
    while(data[j]!='\0'){
        // 注意这里移动到对应的位置
        while(data[j]!=data[i]&&i>0){
            i=next[i-1];
        }
        if(data[i]==data[j]){
            i++;  // 向后匹配
        }
        next[j]=i;
        j++;
    }
}
// 利用next数组求解
int kmpMatcher(char* master,char* sub){
    // 获取next数组
    int next[strlen(sub)];
    getNext(sub,next);
    // 开始匹配
    int i=0,j=0;
    while(master[i]!='\0'&&sub[j]!='\0'){
        while(master[i]!=sub[j]&&j>0){
            j=next[j-1];
        }
        if(master[i]==sub[j]){
            j++;
          
        }
        i++;
          
    }
    if(sub[j]=='\0'){
        return i-j;  // 匹配位置
    }
    return -1;
}
int main(int argc,char** argv){
    int res=kmpMatcher(argv[1],argv[2]);
    if(res==-1){
        printf("匹配失败\n");
    }
    else{
        printf("第%d位匹配成功\n",res);
    }
    return 0;
}