// 将二叉树对称变换,其实就是逐层交换左右孩子
#include "../include/baseMethod.h"
// 定义交换的函数
void swapTree(TreeNode* T){
    if(T==NULL){
        return ;
    }
    else{
        // 开始交换
        TreeNode* temp=T->lchild;
        T->lchild=T->rchild;
        T->rchild=temp;
        // 交换完成
        swapTree(T->lchild);
        swapTree(T->rchild);
    }
}
int main(){
    // 首先创建一个树
    TreeNode* T;
    char data[100];
    printf("请输入要用于创建二叉树的字符串:\n");
    scanf("%s",data);
    int index=0;
    createTree(&T,data,&index);
    // 开始交换
    printf("交换之前二叉树的前序遍历为:\n");
    preOrder(T);
    swapTree(T);
    printf("交换之后二叉树的前序遍历为:\n");
    preOrder(T);
    return 0;
}