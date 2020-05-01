#include <iostream>

using namespace std;


//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������58��һ������ת����˳��
// ��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
// Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "��
// �����"student. a am I"��

#include <cstdio>
#include "../lib/StringUtil.h"
#include <string.h>

char* ReverseSentence(char *pData)
{

    if(pData==nullptr)return nullptr;
    char *start=pData;
    char *tail=pData;
    //reverse whole sentence
    while(*start==' ')start++;
    while(*tail!='\0')tail++;
    tail--;
    Reverse(start,tail);
    //reverse word
    tail=start;
    while(*start!='\0'){
        while(*start==' '){start++;tail++;}
        if(*tail==' '||*tail=='\0'){
            Reverse(start,--tail);
            start = ++tail;
        }else{
            tail++;
        }
    }

    return pData;
}

// ====================���Դ���====================
void Test(const char* testName, char* input, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if((input == nullptr && expectedResult == nullptr)
        || (input != nullptr && strcmp(input, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// ���ܲ��ԣ��������ж������
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// ���ܲ��ԣ�������ֻ��һ������
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// ³���Բ���
void Test3()
{
    Test("Test3", nullptr, nullptr);
}

// �߽�ֵ���ԣ����Կ��ַ���
void Test4()
{
    Test("Test4", "", "");
}

// �߽�ֵ���ԣ��ַ�����ֻ�пո�
void Test5()
{
    char input[] = "   ";
    char expected[] = "   ";
    Test("Test5", input, expected);
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
