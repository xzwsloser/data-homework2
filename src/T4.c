// 层次遍历二叉树
#include "../include/queue.h"
void levelOrder(TreeNode* T){
    // 首先入队
    QueueNode* head=buildQueue();
    enQueue(head,T);
    while(!isQueueEmpty(head)){
        // 开始出队
        QueueNode* temp=deQueue(head);
        printf("%c ",temp->T->data);
        if(temp->T->lchild){
            enQueue(head,temp->T->lchild);
        }
        if(temp->T->rchild){
            enQueue(head,temp->T->rchild);
        }
    }
}
int main(){
    // 首先创建树
    char data[100];
    int index=0;
    printf("请输入用于创建二叉树所使用的字符序列:\n");
    scanf("%s",data);
    TreeNode* T;
    createTree(&T,data,&index);
    printf("层次遍历的结果为:\n");
    levelOrder(T);
    return 0;
}