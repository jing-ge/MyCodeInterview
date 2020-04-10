#include <iostream>

#include <cstdio>
#include <map>
#include <ComplexList.h>
using namespace std;

//使用原始的方法O（n2）
ComplexListNode* findnode(ComplexListNode* head,int val)
{
    while(head!=nullptr){
        if(head->m_nValue==val)return head;
        head = head->m_pNext;
    }
    return nullptr;
}
ComplexListNode* Clone1(ComplexListNode* pHead)
{
    if (pHead==nullptr)return nullptr;
    ComplexListNode* node = pHead;

    ComplexListNode* clonehead = new ComplexListNode();
    clonehead->m_nValue = pHead->m_nValue;
    clonehead->m_pSibling = nullptr;
    ComplexListNode* tnode = clonehead;

    while(node->m_pNext!=nullptr){
        node = node->m_pNext;
        ComplexListNode* cnode = new ComplexListNode();
        cnode->m_nValue = node->m_nValue;
        cnode->m_pSibling = nullptr;
        tnode->m_pNext = cnode;

        tnode = tnode->m_pNext;
    }

    tnode = clonehead;
    node = pHead;
    while(tnode!=nullptr){
        if(node->m_pSibling==nullptr){
            node = node->m_pNext;
            tnode = tnode->m_pNext;
            continue;
        }
        ComplexListNode* sbnode = findnode(clonehead,node->m_pSibling->m_nValue);
        tnode->m_pSibling = sbnode;
        node = node->m_pNext;
        tnode = tnode->m_pNext;
    }
    return clonehead;
}
//使用map
ComplexListNode* Clone2(ComplexListNode* pHead)
{
    if (pHead==nullptr)return nullptr;
    ComplexListNode* node = pHead;
    map<ComplexListNode*,ComplexListNode*> mymap;

    ComplexListNode* clonehead = new ComplexListNode();
    clonehead->m_nValue = pHead->m_nValue;
    clonehead->m_pSibling = nullptr;
    ComplexListNode* tnode = clonehead;
    mymap[pHead] = clonehead;

    while(node->m_pNext!=nullptr){
        node = node->m_pNext;
        ComplexListNode* cnode = new ComplexListNode();
        cnode->m_nValue = node->m_nValue;
        cnode->m_pSibling = nullptr;
        tnode->m_pNext = cnode;

        tnode = tnode->m_pNext;
        mymap[node] =tnode;
    }

    tnode = clonehead;
    node = pHead;
    while(tnode!=nullptr){
        if(node->m_pSibling==nullptr){
            node = node->m_pNext;
            tnode = tnode->m_pNext;
            continue;
        }
        ComplexListNode* sbnode = mymap[node->m_pSibling];
        tnode->m_pSibling = sbnode;
        node = node->m_pNext;
        tnode = tnode->m_pNext;
    }
    return clonehead;
}
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);
ComplexListNode* Clone3(ComplexListNode* pHead)
{
    if(pHead==nullptr)return nullptr;
    //为每一个node复制一遍
    ComplexListNode* node =pHead;
    while(node!=nullptr){
        ComplexListNode* tnode = new ComplexListNode();
        tnode->m_nValue = node->m_nValue;
        tnode->m_pSibling = nullptr;
        tnode->m_pNext = node->m_pNext;
        node->m_pNext = tnode;
        node = tnode->m_pNext;
    }

    //复制sub
    node = pHead;
    while(node!=nullptr){
        ComplexListNode* tnode = node->m_pNext;
        if(node->m_pSibling!=nullptr)
        tnode->m_pSibling = node->m_pSibling->m_pNext;
        node = tnode->m_pNext;
    }
    //切断联系
    ComplexListNode* clonehead = pHead->m_pNext;
    node = clonehead;
    while(node->m_pNext!=nullptr){
        node->m_pNext = node->m_pNext->m_pNext;
        node = node->m_pNext;
    }
    return clonehead;
}

//
//void CloneNodes(ComplexListNode* pHead);
//void ConnectSiblingNodes(ComplexListNode* pHead);
//ComplexListNode* ReconnectNodes(ComplexListNode* pHead);
//
//ComplexListNode* Clone(ComplexListNode* pHead)
//{
//    CloneNodes(pHead);
//    ConnectSiblingNodes(pHead);
//    return ReconnectNodes(pHead);
//}
//
//void CloneNodes(ComplexListNode* pHead)
//{
//    ComplexListNode* pNode = pHead;
//    while(pNode != nullptr)
//    {
//        ComplexListNode* pCloned = new ComplexListNode();
//        pCloned->m_nValue = pNode->m_nValue;
//        pCloned->m_pNext = pNode->m_pNext;
//        pCloned->m_pSibling = nullptr;
//
//        pNode->m_pNext = pCloned;
//
//        pNode = pCloned->m_pNext;
//    }
//}
//
//void ConnectSiblingNodes(ComplexListNode* pHead)
//{
//    ComplexListNode* pNode = pHead;
//    while(pNode != nullptr)
//    {
//        ComplexListNode* pCloned = pNode->m_pNext;
//        if(pNode->m_pSibling != nullptr)
//        {
//            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
//        }
//
//        pNode = pCloned->m_pNext;
//    }
//}
//
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = nullptr;
    ComplexListNode* pClonedNode = nullptr;

    if(pNode != nullptr)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while(pNode != nullptr)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;

        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    return pClonedHead;
}

// ====================测试代码====================
void Test(const char* testName, ComplexListNode* pHead)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode* pClonedHead = Clone3(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
    ComplexListNode* pNode1 = CreateNode(1);
    BuildNodes(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
