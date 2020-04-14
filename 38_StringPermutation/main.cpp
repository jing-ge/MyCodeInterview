#include <iostream>

using namespace std;

#include <cstdio>

void Permutation(char* pStr, char* pBegin);

void Permutation(char* pStr)
{
    if(pStr==nullptr)return;
    Permutation(pStr,pStr);
}

void Permutation(char* pStr, char* pBegin)
{
    if(*pBegin=='\0'){
        printf("%s\n",pStr);
    }else{
        for(char*pch= pBegin;*pch!='\0';*pch++){
            char tmp = *pch;
            *pch = *pBegin;
            *pBegin = tmp;
            Permutation(pStr,pBegin+1);

            tmp = *pch;
            *pch = *pBegin;
            *pBegin = tmp;

        }
    }
}

// ====================≤‚ ‘¥˙¬Î====================
void Test(char* pStr)
{
    if(pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(nullptr);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);

    return 0;
}

