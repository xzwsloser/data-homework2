#include "../include/baseMethod.h"
// 创建二叉树
void createTree(TreeNode** T,char* data,int* index){
    char ch=data[*index];
    *index+=1;
    if(ch=='#'){
        (*T)=NULL;
    }
    else{
        (*T)=(TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data=ch;
        (*T)->flag=0;
        // 开始递归
        createTree(&((*T)->lchild),data,index);
        createTree(&((*T)->rchild),data,index);
    }
}
// 递归方式先序遍历二叉树
void preOrder(TreeNode* T){
    if(T==NULL){
        return ;
    }
    else{
        printf("%c ",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
// 中序遍历二叉树
void inOrder(TreeNode* T){
    if(T==NULL){
        return ;
    }
    else{
        inOrder(T->lchild);
        printf("%c ",T->data);
        inOrder(T->rchild);
    }
    
}
// 后序遍历二叉树
void backOrder(TreeNode* T){
    if(T==NULL){
        return ;
    }
    else{
        backOrder(T->lchild);
        backOrder(T->rchild);
        printf("%c ",T->data);
    }
}
// 定义一个返回节点的函数
TreeNode* getCertainNode(TreeNode*  T,char data){
    // 如何进行遍历寻找对应节点
    if(T==NULL){
        return NULL;
    }
    else{
        if(T->lchild&&T->lchild->data==data){
            return T->lchild;
        }
        else if(T->rchild&&T->rchild->data==data){
            return T->rchild;
        }
        TreeNode* left=getCertainNode(T->lchild, data);
        TreeNode* right=getCertainNode(T->rchild,data);
        if(left==NULL&&right==NULL){
            return NULL;
        }
        return left==NULL?right:left;
    }
}
