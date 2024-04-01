// 求解第k层节点个数,还是利用队列的数据结构
#include "../include/queue.h"

// 一层一层遍历
int getLevelNode(TreeNode* T,int k){
    // 首先还是入队
    QueueNode* head=buildQueue();
    enQueue(head,T);
    int count=1; // 记录层数
    int nodeCount=1;
    while(!isQueueEmpty(head)){
        int rcount=0;
        for(int i=0;i<nodeCount;i++){
            // 首先出栈
            QueueNode* temp=deQueue(head);
            if(temp->T->lchild){
                enQueue(head,temp->T->lchild);
                rcount++;
            }
            if(temp->T->rchild){
                enQueue(head,temp->T->rchild);
                rcount++;
            }
        }
        // 添加完成
        count++;
        nodeCount=rcount; 
        if(count==k){
            return nodeCount;
        }
    }
    return -1;
}
int main(int argc,char** argv){
    int index=0;
    TreeNode* T;
    createTree(&T,argv[1],&index);
    int k;
    printf("请输入要查看节点的层数:\n");
    scanf("%d",&k);
    printf("第%d层的节点个数为: %d",k,getLevelNode(T,k));
    return 0;
}