#include<stdio.h>
#include<stdlib.h>
void levelTravel(char* data){
    int i=0;
    while(data[i]!='\0'){
        printf("%c ",data[i]);
    }
}
int main(int argc,char** argv){
    printf("层次遍历为: %s\n",argv[1]);
}