#include <iostream>
#include <../lib/List.h>
using namespace std;

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(pListHead==nullptr || pToBeDeleted ==nullptr)
        return;
    if(pToBeDeleted->m_pNext!=nullptr)
    {
        ListNode* next = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = next->m_nValue;
        pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;
        delete next;
        next = nullptr;
    }
    else if(*(pListHead)==pToBeDeleted)
    {
         delete pToBeDeleted;
         pToBeDeleted = nullptr;
         *pListHead = nullptr;
    }
    else
    {
        ListNode* tmp = *pListHead;
        while(tmp->m_pNext!=pToBeDeleted){
            tmp = tmp->m_pNext;
        }
        tmp->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

// ====================���Դ���====================
void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);

    printf("The result list is: \n");
    PrintList(pListHead);
}

// �������ж����㣬ɾ���м�Ľ��
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��β���
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��ͷ���
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// ������ֻ��һ����㣬ɾ��ͷ���
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// ����Ϊ��
void Test5()
{
    Test(nullptr, nullptr);
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
