// 根据前序遍历和中序遍历得到二叉树
// A B D E C F G    ===   D B E A F C G  ===> A B C D E F G 
// 还是利用这个算法
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char getTree(char* preData,char* inData,char* data,int pl,int pr,int il,int ir,int n){
    // 首先还是找到,起始就是不但找到根节点
    if(pl>pr||il>ir){
        return ;
    }

    char root=preData[pl]; // 找到起始位置
   
    char ch=root;
    data[n]=ch;
    // 找到根节点的位置
    int i=0;
    while(inData[i]!=root){
        i++;
    }
    // 找到之后开始找到根节点
    int leftSize=i-il;
    getTree(preData,inData,data,pl+1,pl+leftSize,il,i-1,2*n+1);
    getTree(preData,inData,data,pl+leftSize+1,pr,i+1,ir,2*n+2);
    return ch;

}
int main(int argc,char** argv){
    char* preData=argv[1];
    char* inData=argv[2];  
    char* data=(char*)malloc(sizeof(char)*strlen(preData));
    getTree(preData,inData,data,0,strlen(preData)-1,0,strlen(inData)-1,0);
    printf("得到的序列为: %s\n",data);
}