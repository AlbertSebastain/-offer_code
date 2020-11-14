#include <iostream>
#include <cstdio>

/*

AUTHOR: shi
date 
*/
using namespace std;
BinaryTreeNode* Construct(int*,int*,int);
BinaryTreeNode* ConstructCore(int*,int*,int*,int*);
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;

};
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    // preorder 前序遍历
    // inorder 中序遍历
    if(preorder == nullptr || inorder == nullptr || length <0)
    {
        return nullptr;
    }
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}
BinaryTreeNode* ConstructCore(int* startpreorder, int* endpreorder, int* startinorder, int* endinorder)
{
    BinaryTreeNode* root = new BinaryTreeNode;
    int rootValue = startpreorder[0];
    root -> m_nValue = rootValue;
    root -> m_pLeft = nullptr;
    root -> m_pRight = nullptr;
    if(startpreorder == endpreorder)
    {
        if (startinorder == endinorder && *startpreorder == *startinorder)
        {
            return root;
        }
        else
        {
            throw std::exception("Invalid Input.");
        }
        
    }
    int* rootinorder = startpreorder;
    while((*rootinorder != rootValue) && (rootinorder <= endinorder) )
    {
        rootinorder = rootinorder+1;
    }
    if((rootinorder == endinorder) && (*rootinorder != rootValue))
    {
        throw std::exception("invalid Input.");
    }
    int leftlength = rootinorder-startinorder;
    int rightlength = endinorder-rootinorder;
    int* leftpreorderend = startpreorder+leftlength;
    if(leftlength > 0)
    {
        root -> m_pLeft = ConstructCore(startpreorder+1,leftpreorderend,startinorder,rootinorder-1);

    }
    if(leftlength < endpreorder-startpreorder)
    {
        /* leftlength 小于 长度length，说明存在右子树，特殊情况如果二叉树不平衡，不存在右子树。*/
        root -> m_pRight = ConstructCore(startpreorder+leftlength,endpreorder,rootinorder+1,endinorder);
    }
    return root;

}

int main(){
   
   return 0;
}
