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

// ====================测试代码====================
void Test(const char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    Test(nullptr, '\0');

    return 0;
}
