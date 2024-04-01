// 上面题目理解错了
#include "../include/queue.h"
#include "../include/baseMethod.h"
// 其实就是记录队列中元素
int getMaxLength(TreeNode* T){
    QueueNode* head=buildQueue();
    int count=0; // 记录队列中的元素个数
    int max=0;
    enQueue(head,T);
    count++;
    while(!isQueueEmpty(head)){
        // count就是元素个数
        int rcount=0;  // 记录下一层元素
        for(int i=0;i<count;i++){
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
        // 统计元素结束
        count=rcount;
        if(count>max){
            max=count;
        }
    }
    return max;
}
int main(){
    char data[100];
    int index=0;
    TreeNode* T;
    printf("请输入用于创建二叉树的字符序列:\n");
    scanf("%s",data);
    createTree(&T,data,&index);
    printf("树的宽度为: %d\n",getMaxLength(T));
}