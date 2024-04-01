// 利用前序遍历的结果和中序遍历的结构构造一个二叉树
/**
 *  前序: 根->左->右
 *  中序: 左->根->右
 *   利用前序遍历确定根节点,之后利用中序遍历确定左子树和右子树
*/
#include "../include/baseMethod.h"
#include <string.h>
TreeNode* createTreeBySubsequence(char* preData,char* inData,int pL,int pR,int iL,int iR){
    // 每一次只用考虑根节点就可以了
    if(pL>pR||iL>iR){  // 注意这里为什么用或者,因为如果一个序列没有了,
                        //就无法就在另外的序列中遍历得到相关信息
        return NULL;
    }
    else{
    TreeNode* T=(TreeNode*)malloc(sizeof(TreeNode));
    // 首先还是找到序列
    char root=preData[pL]; // 找到根节点
    T->data=root;
    int i=iL;
    while(inData[i]!=root){
        i++;
    }
    // 找到对应的位置之后就可以开始定义左子树和右子树的前序和中序遍历范围
    // 左子树的前序遍历长度为
    // 一定要搞清楚遍历区间的含义
    int leftSize=i-iL;
    T->lchild=createTreeBySubsequence(preData,inData,pL+1,pL+leftSize,iL,i-1);
    // 注意要跳过原来的头节点
    T->rchild=createTreeBySubsequence(preData,inData,pL+leftSize+1,pR,i+1,iR);
    return T;
    }

}
int main(){
    printf("请输入先序遍历的序列:\n");
    char preData[100];
    scanf("%s",preData);
    printf("请输入中序遍历的序列:\n");
    char inData[100];
    scanf("%s",inData);
    TreeNode* T=createTreeBySubsequence(preData,inData,0,strlen(preData)-1,0,strlen(inData)-1);
    printf("先序遍历的结果为:\n");
    preOrder(T);
    printf("\n");
    printf("中序遍历的结果为:\n");
    inOrder(T);
    printf("\n");
    return 0;
}