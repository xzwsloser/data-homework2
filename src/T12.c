// 使用非递归的方式实现前序中序和后序遍历
#include "../include/stack.h"
// 先序遍历节点,其实就是入栈时访问节点即可
void preOrderBynormal(TreeNode* T){
    // 首先创建队列
    TreeNode* node=T;
    StackNode* head=createStack();
    while(node||!isStackEmpty(head)){
        // 不断找到左孩子
        if(node){
            printf("%c ",node->data);
            push(head,node);
            node=node->lchild;
        }
        else{
            // 开始出栈,才做右边的孩子
            node=pop(head)->T;
            node=node->rchild;  // 为什么? 其实就是栈顶元素已经被访问过了,在这一个节点上相当于一个根节点,所以需要访问右子树
            // 意思就是根节点就是栈顶元素的下一个元素,根元素就是左孩子
        }
    }
}
void  inOrderBynormal(TreeNode* T){
    TreeNode* node=T;
    StackNode* head=createStack();
    while(node||!isStackEmpty(head)){
        if(node){
            push(head,node);
            node=node->lchild;
        }
        else{
            node=pop(head)->T;
            printf("%c ",node->data);
            node=node->rchild;
        }
    }
}
// 非递归方式实现后序遍历
void backOrderBynormal(TreeNode* T){
    TreeNode* node=T;
    StackNode* head=createStack();
    while(node||!isStackEmpty(head)){
        // 如何实现后序遍历,首先还是找到左孩子
        if(node){
            push(head,node);
            node=node->lchild;
        }
        else{
            // 开始出栈访问元素,此时栈顶元素就是根节点的元素
            TreeNode* top=getTop(head)->T;
            if(top->rchild!=NULL&&top->rchild->flag==0){
                // 开始入栈
                top=top->rchild;
                push(head,top);
                node=top->lchild;
            }
            else{
                // 开始出栈
                top=pop(head)->T;
                printf("%c ",top->data);
                // 开始操作上面一级元素
                top->flag=1; 
                
            }
        }
    }
}
int main(int argc,char** argv){
    TreeNode* T;
    int index=0;
    createTree(&T,argv[1],&index);
    printf("非递归方式实现的前序遍历为:\n");
    preOrderBynormal(T);
    printf("\n");
    printf("非递归方式实现的中序遍历为:\n");
    inOrderBynormal(T);
    printf("\n");
    printf("非递归方式实现的后序遍历为:\n");
    backOrderBynormal(T);
    printf("\n");
}