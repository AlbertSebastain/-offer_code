#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
/*
autor: shi
date:2020
*/

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
void AddToTail(ListNode**, int);
void RemoveNode(ListNode** , int);
void print_val(ListNode**);
void PrintListReverse(ListNode*);
void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew -> m_nValue = value;
    pNew -> m_pNext = nullptr;
    if (*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode -> m_pNext != nullptr)
        {
            pNode = pNode -> m_pNext;
        }
        pNode -> m_pNext = pNew;
    }
    return;
}
void RemoveNode(ListNode** pHead, int value)
{
    if((*pHead) -> m_nValue == value)
    {
        (*pHead) = (*pHead) -> m_pNext;
        return;
    }
    else
    {
        ListNode* Node;
        Node = *pHead;
        while(Node -> m_pNext -> m_nValue != value && Node -> m_pNext != nullptr)
        {
            Node = Node -> m_pNext;
        }
        Node -> m_pNext = Node -> m_pNext ->m_pNext;
        while(Node -> m_pNext != nullptr)
        {
            Node = Node -> m_pNext;
        }
    }
    return;

}
void print_val(ListNode** pHead)
{
    ListNode* Node = *pHead;
    while(Node -> m_pNext != nullptr)
    {
        printf("%d,",Node -> m_nValue);
        Node = Node -> m_pNext;
    }
    printf("%d\n",Node ->m_nValue);
    //printf("\n");
}
void PrintListReverse(ListNode *pHeads)
{
    stack<ListNode*> Nodes;
    ListNode* aNode;
    aNode = pHeads;
    while(aNode -> m_pNext != nullptr)
    {
        Nodes.push(aNode);
        aNode = aNode -> m_pNext;
    }
    Nodes.push(aNode);
    ListNode* bNodes;
    while(!Nodes.empty())
    {
        bNodes = Nodes.top();
        cout<<bNodes -> m_nValue<<',';
        Nodes.pop();
    }
}
int main()
{
    ListNode** pHead = new ListNode*;
    int value = 3;
    AddToTail(pHead,value);
    int value_1 = 4;
    AddToTail(pHead,value_1);
    int value_11 = 5;
    AddToTail(pHead,value_11);
    int value_111 = 6;
    AddToTail(pHead,value_111);
    print_val(pHead);
    RemoveNode(pHead,value_11);
    print_val(pHead);
    PrintListReverse(*pHead);
    return 0;
}