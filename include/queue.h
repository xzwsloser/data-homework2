#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "baseMethod.h"
typedef struct queuenode{
    TreeNode* T;
    struct queuenode* next;
}QueueNode;
QueueNode* buildQueue();
// 这里利用头删尾插法模拟入队和出队过程
void  enQueue(QueueNode* head,TreeNode* T);
// 头删法删除元素
QueueNode* deQueue(QueueNode* head);
// 判空
int isQueueEmpty(QueueNode* head);


#endif