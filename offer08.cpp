#include <iostream>
#include <cstdio>

/*

AUTHOR: shi
date 
*/
using namespace std;
BinaryTreeNode* GetNext(BinaryTreeNode*);
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;

};
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
    {
        return nullptr;
    }
    BinaryTreeNode* pNext;
    if(pNode -> m_pRight != nullptr)
    {
        BinaryTreeNode* pRight = pNode -> m_pRight;
        while(pRight -> m_pLeft != nullptr)
        {
            pRight = pRight -> m_pLeft;
        }        
        pNext = pRight;  
    }
    else
    {
        if(pNode == pNode -> m_pParent -> m_pLeft)
        {
            pNext = pNode -> m_pParent;
        }
        else
        {
            pNext = pNode;
            while((pNext -> m_pParent != nullptr) && (pNext != pNext -> m_pParent -> m_pLeft))
            {
                pNext = pNode -> m_pParent;
            }
            pNext = pNext -> m_pParent;
        }

    }
    return pNext;
}
int main(){
   
   return 0;
}
