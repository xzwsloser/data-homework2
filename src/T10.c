#include "../include/baseMethod.h"
// 判断两颗二叉树的结构是否相同,其实就是同步遍历两个节点
int isSameTree(TreeNode* T1,TreeNode* T2){
    // 只需要一个有一个没有即可
    if((T1==NULL&&T2!=NULL)||(T1!=NULL&&T2==NULL)){
        return 0;
    }
    if(T1==NULL&&T2==NULL){
        return 1;
    }
    
    // 其他的情况
    return isSameTree(T1->lchild,T2->lchild)&&isSameTree(T1->rchild,T2->rchild);
}
int main(int argc,char* argv[]){
    // 创建二叉树
    TreeNode* T1;
    TreeNode* T2;
    int index1=0;
    int index2=0;
    createTree(&T1,argv[1],&index1);
    createTree(&T2,argv[2],&index2);
    if(isSameTree(T1,T2)){
        printf("两棵树的结构相同\n");
    }
    else{
        printf("两棵树的结构不同\n");
    }
    return 0;
}