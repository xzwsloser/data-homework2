#include<stdio.h>
#include<stdlib.h>
// 找到节点个数
int getNodeNum(char* data){
    int count=0;
    int i=0;
    while(data[i]!='\0'){
        if(data[i]!='#'){
            count++;
            i++;
        }
    }
    return count;
    
}
int main(int argc,char** argv){
    char* data=argv[1];
    printf("节点个数为: %d\n",getNodeNum(argv[1]));
    return 0;
}