// 求解二叉树的宽度,还是利用递归算法
#include "../include/baseMethod.h"
int getLeftMax(TreeNode* T){
    // 找到最左边的宽度,其实就是向左边就可以减少
    int lstart=0;
    int rstart=0;
    int min=lstart;
    TreeNode* leftNode=T;
    TreeNode* rightNode=T;
    if(T->lchild==NULL&&T->rchild==NULL){
        return 0;
    }
    else{
            if(leftNode->lchild){
        // 向左边遍历
        leftNode=leftNode->lchild;
        lstart--;
        lstart+=getLeftMax(leftNode);
        if(lstart<min){
            min=lstart;
        }
    }
    if(rightNode->rchild){
        // 向右边遍历
        rightNode=rightNode->rchild;
        rstart++;
        rstart+=getLeftMax(rightNode);
        if(rstart<min){
            min=rstart;
        } 
    }
        return min;
    }

}
int getRightMax(TreeNode* T){
        // 找到最左边的宽度,其实就是向左边就可以减少
    int lstart=0;
    int rstart=0;
    int max=lstart;
    TreeNode* leftNode=T;
    TreeNode* rightNode=T;
    if(T->lchild==NULL&&T->rchild==NULL){
        return 0;
    }
    else{
            if(leftNode->lchild){
        // 向左边遍历
        leftNode=leftNode->lchild;
        lstart--;
        lstart+=getRightMax(leftNode);
        if(lstart>max){
            max=lstart;
        }
    }
    if(rightNode->rchild){
        // 向右边遍历
        rightNode=rightNode->rchild;
        rstart++;
        rstart+=getRightMax(rightNode);
        if(rstart>max){
            max=rstart;
        } 
    }
        return max;
    }
}
int main(){
    printf("请输入创建二叉树使用的序列:\n");
    char data[100];
    scanf("%s",data);
    int index=0;
    TreeNode* T;
    createTree(&T,data,&index);
    int maxLength=getRightMax(T)-getLeftMax(T);
    printf("树的宽度为: %d\n",maxLength);
    return 0;
}