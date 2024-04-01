#include "../include/baseMethod.h"
// 求解叶子节点的个数
int getLeavesSum(TreeNode* T){
    if(T==NULL){
        return 1;
    }
    else{
        return getLeavesSum(T->lchild)+getLeavesSum(T->rchild);
    }
}
int main(int argc,char** argv){
    int index=0;
    TreeNode* T;
    createTree(&T,argv[1],&index);
    printf("叶子节点的个数为: %d\n",getLeavesSum(T));
    return 0;
}