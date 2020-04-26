#include <iostream>

using namespace std;


#include <cstdio>
#include <string>

char FirstNotRepeatingChar(const char* pString)
{
    if(pString==nullptr)return '\0';
    int length = 256;
    int *hashtable = new int[length];
    for(int i=0;i<length;i++){
        hashtable[i]=0;
    }
    const char* tmp = pString;
    while(*tmp!='\0'){
        hashtable[*tmp]++;
        tmp++;
    }
    tmp = pString;
    while(*tmp!='\0'){
        if(hashtable[*tmp]==1)return *tmp;
        tmp++;
    }
    return '\0';
}

// ====================���Դ���====================
void Test(const char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // ����������ԣ�����ֻ����һ�ε��ַ�
    Test("google", 'l');

    // ����������ԣ�������ֻ����һ�ε��ַ�
    Test("aabccdbd", '\0');

    // ����������ԣ������ַ���ֻ����һ��
    Test("abcdefg", 'a');

    // ³���Բ��ԣ�����nullptr
    Test(nullptr, '\0');

    return 0;
}
