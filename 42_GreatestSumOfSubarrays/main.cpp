#include <iostream>

using namespace std;

#include <cstdio>


bool g_InvalidInput = false;
int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if(pData==nullptr||nLength<=0){
        g_InvalidInput = true;
        return 0;
    }
    int res = *pData;
    int maxres = res;
    for(int i=1;i<nLength;i++){
        if(res<=0){
            res = pData[i];
        }else{
            res += pData[i];
        }
        if(res>maxres)maxres=res;
    }
    return maxres;
}

// ====================���Դ���====================
void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int result = FindGreatestSumOfSubArray(pData, nLength);
    if(result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// �������ֶ��Ǹ���
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// �������ֶ�������
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// ��Ч����
void Test4()
{
    Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
