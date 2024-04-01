#ifndef _BASEMETHOD_H_
#define _BASEMETHOD_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct treenode{
    char data;
    struct treenode* lchild;
    struct treenode* rchild;
    int flag;    // 后序遍历中判断节点是否被访问过
}TreeNode;

// 创建二叉树
void createTree(TreeNode** T,char* data,int* index);
// 递归方式先序遍历二叉树
void preOrder(TreeNode* T);
// 中序遍历二叉树
void inOrder(TreeNode* T);
// 后序遍历二叉树
void backOrder(TreeNode* T);
TreeNode* getCertainNode(TreeNode*  T,char data);
#endif