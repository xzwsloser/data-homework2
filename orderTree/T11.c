#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stacknode{
    char data;
    struct stacknode* next;
}StackNode;
StackNode* initStack();
int isEmpty(StackNode* head);
void push(StackNode* head,char ch);
int findIndex(char*  data,char ch);
void  preOrder(char* data);
StackNode* pop(StackNode* head);
// 创建
StackNode* initStack(){
    StackNode* head=(StackNode*)malloc(sizeof(StackNode));
    head->data=' ';
    head->next=NULL;
}
// 判空
int isEmpty(StackNode* head){
    if(head->next==NULL){
        return 1;
    }
        return 0;
    
}
// 头插法
void push(StackNode* head,char ch){
    StackNode* pnew=(StackNode*)malloc(sizeof(StackNode));
    pnew->data=ch;
    pnew->next=head->next;
    head->next=pnew;
}
// 尾删除
StackNode* pop(StackNode* head){
    if(isEmpty(head)){
        return NULL;
    }
    else{
        StackNode* temp=head->next;
        head->next=temp->next;
        return temp;
    }
}
int findIndex(char*  data,char ch){
    int i=0;
    while(data[i]!=ch){
        i++;
    }
    return i;
}
void  preOrder(char* data){
        int nodeIndex=0;
        StackNode* head=initStack();
        while(nodeIndex<strlen(data)||!isEmpty(head)){
            if(nodeIndex>=strlen(data)){
                printf("%c ",data[nodeIndex]);
                push(head,data[nodeIndex]);
                nodeIndex=2*nodeIndex+1;
            }
            else{
                nodeIndex=findIndex(data,pop(head)->data);
                nodeIndex=2*nodeIndex+2;
            }
        }
}
int main(int argc,char** argv){
    printf("先序遍历为:\n");
    preOrder(argv[1]);
}