#include "../include/stack.h"
// 构建栈的数据结构
StackNode* createStack(){
    StackNode* head=(StackNode*)malloc(sizeof(StackNode));
    head->T=NULL;
    head->next=NULL;
}
// 利用头插法插入元素
void push(StackNode* head,TreeNode* T){
    StackNode* pnew=(StackNode*)malloc(sizeof(StackNode));
    pnew->T=T;
    pnew->next=head->next;
    head->next=pnew;
}
// 利用头删法删除元素
StackNode* pop(StackNode* head){
    if(isStackEmpty(head)){
        return NULL;
    }
    else{
        StackNode* temp=head->next;
        head->next=temp->next;
        return temp;      
    }
    
}
// 判断栈是否为空
int isStackEmpty(StackNode* head){
    return head->next==NULL;
}
// 获取栈顶元素
StackNode* getTop(StackNode* head){
    return head->next;
}