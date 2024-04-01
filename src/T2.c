// 求解二叉树的最大深度,思考还是可以利用递归算法
#include "../include/baseMethod.h"
int getDepth(TreeNode* T);
int getDepth(TreeNode* T){
   
    if(T==NULL){
        return 0;
    }
    else{
         int depth=1;  // 其实就是其实深度
        int ldepth=getDepth(T->lchild);
        int rdepth=getDepth(T->rchild);
        int realDepth=(ldepth>=rdepth)?ldepth:rdepth;
        depth+=realDepth;
        return depth;
    }
}
int main(){
    // 建立二叉树
    char data[100];
    int index=0;
    printf("请输入字母序列并且建立二叉树\n");
    scanf("%s",data);
    TreeNode* T;
    createTree(&T,data,&index);
    printf("树的中序遍历为:\n");
    inOrder(T);
    printf("树的深度为: %d\n",getDepth(T));
    return 0;
}