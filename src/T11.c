// 求解二叉树中两个节点的最低公共祖先节点,如果利用三指针的方法进行寻找,
// 只需要不断向上面遍历只要向上不断搜寻范围就可以了
// 如果不是三指针呢?
#include "../include/baseMethod.h"
TreeNode* getNearancestor(TreeNode* T,TreeNode* T1,TreeNode* T2){
    // 其实就是找到分布树的范围
    // 首先定义两个节点寻找
    if(T==NULL||T==T1||T==T2){
        return T;
    }
    // 就是如果遍历到本身就可以返回了
    TreeNode* left=getNearancestor(T->lchild,T1,T2);
    TreeNode* right=getNearancestor(T->rchild,T1,T2);
    if(left!=NULL&&right!=NULL){
        return T;  // 就是分布在不同的子树上就可以返回了
    }
    return left==NULL?right:left;  // 在一个子树中
}
int main(int argc,char** argv){
    // 首先构造节点
    TreeNode* T;
    int index=0;
    createTree(&T,argv[1],&index);
    // 构造节点
    TreeNode* T1=getCertainNode(T,'B');
    TreeNode* T2=getCertainNode(T,'F');
    TreeNode* res=getNearancestor(T,T1,T2);
    if(res){
        printf("公共祖先节点对应的元素为: %c\n",res->data);
    }
    else{
        printf("没有公共节点\n");
    }
}
