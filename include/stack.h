#ifndef _STACK_H_
#define _STACK_H_
#include "../include/baseMethod.h"
typedef struct stacknode{
    TreeNode* T;
    struct stacknode* next;
}StackNode;
#include "../include/stack.h"
// 构建栈的数据结构
StackNode* createStack();
// 利用头插法插入元素
void push(StackNode* head,TreeNode* T);
// 利用头删法删除元素
StackNode* pop(StackNode* head);
// 判断栈是否为空
int isStackEmpty(StackNode* head);
// 获取栈顶元素
StackNode* getTop(StackNode* head);
#endif