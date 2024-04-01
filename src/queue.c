#include "../include/queue.h"
QueueNode* buildQueue(){
    // 构造一个队列
    QueueNode* head=(QueueNode*)malloc(sizeof(QueueNode));
    head->T=NULL;
    head->next=NULL;
}
int isQueueEmpty(QueueNode* head){
    if(head->next==NULL){
        return 1;
    }
    return 0;
}
// 这里利用头删尾插法模拟入队和出队过程
void  enQueue(QueueNode* head,TreeNode* T){
    QueueNode* pnew=(QueueNode*)malloc(sizeof(QueueNode));
    pnew->T=T;
    // 首先找到尾节点
    QueueNode* pstr=head;
    while(pstr->next!=NULL){
        pstr=pstr->next;
    }
    pstr->next=pnew;
    pnew->next=NULL;
}
// 头删法删除元素
QueueNode* deQueue(QueueNode* head){
    if(isQueueEmpty(head)){
        return NULL;
    }
    else{
        QueueNode* temp=head->next;
        head->next=temp->next;
        return temp;
    }
}
