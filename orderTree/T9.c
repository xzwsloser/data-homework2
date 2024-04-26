#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isMirrorAble(char* data1,char* data2){
    if(strlen(data1)!=strlen(data2)){
        return 0;
    }
    int i=0;
    while(data1[i]!='\0'&&data2[i]!='\0'){
        if(!(data1[i]!='#'&&data2[i]!='#')){
            return 0;
        }
        i++;
       
    }
    return 1;
}
int main(int argc,char** argv){
    int res=isMirrorAble(argv[1],argv[2]);
    if(res){
        printf("结构相同\n");
    }
    else{
        printf("结构不同\n");
    }
}
