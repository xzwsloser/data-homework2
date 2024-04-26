#include<stdio.h>
#include<stdlib.h>
int findIndex(char* data,char ch);
char findAncenstor(char* data,char ch1,char ch2){
    int index1=findIndex(data,ch1);
    int index2=findIndex(data,ch2);
    // 不断相处
    
        while(index1!=index2&&index1>0&&index2>0){
            if(index1>index2){
                index1/=2;
            }
            else if(index1<index2){
                index2/=2;
            }
            
        }
        if(index1==index2){
            return data[index1];
        }
        else{
        return 0;
        }
    

}
int findIndex(char* data,char ch){
    int i=0;
    while(data[i]!=ch){
        i++;
    }
    return i;
}
int main(){
    char* data="ABCDEFG";
    printf("D和E对应父节点为 %c\n",findAncenstor(data,'D','E'));
    return 0;
}