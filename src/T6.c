// 求解尔二叉树中的节点个数,可以利用递归也可以利用数据结构
#include "../include/baseMethod.h"
int getNodeSum(TreeNode* T){
    // 首先终止条件 ?
    if(T==NULL){
        return 0;
    }
    else{
        return 1+getNodeSum(T->lchild)+getNodeSum(T->rchild);
    }
}
int main(int argc,char* argv[]){
    TreeNode* T;
    int index=0;
    // char data[100];
    // printf("请输入用于创建二叉树的字符序列:\n");
    // scanf("%s",data);
    createTree(&T,argv[1],&index);
    printf("节点数为: %d\n",getNodeSum(T));
    return 0;
}
