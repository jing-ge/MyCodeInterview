#include <iostream>

using namespace std;


#include <cstdio>
#include <exception>
#include <vector>

int FindNumberAppearingOnce(int numbers[], int length)
{
    if(numbers == nullptr || length <= 0)
        throw "Invalid input.";
    int bitsum[32] = {0};
    for(int i=0;i<length;i++){
        for(int j =0; j<32; j++)
        {
           bitsum[j] += (numbers[i]>>j)&1;
        }
    }
    int res = 0;
    for(int i=31;i>=0;i--){
        int bitres = bitsum[i]%3?1:0;
        res = res<<1;
        res += bitres;
    }
    return res;
}

// ====================���Դ���====================
void Test(const char* testName, int numbers[], int length, int expected)
{
    int result = FindNumberAppearingOnce(numbers, length);
    if(result == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s FAILED.\n", testName);
}

// �������ֶ���������Ψһ����������С��
void Test1()
{
    int numbers[] = { 1, 1, 2, 2, 2, 1, 3 };
    int expected = 3;
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// �������ֶ���������Ψһ�����ֵĴ�Сλ���м�
void Test2()
{
    int numbers[] = { 4, 3, 3, 2, 2, 2, 3 };
    int expected = 4;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// �������ֶ���������Ψһ������������
void Test3()
{
    int numbers[] = { 4, 4, 1, 1, 1, 7, 4 };
    int expected = 7;
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// Ψһ�������Ǹ���
void Test4()
{
    int numbers[] = { -10, 214, 214, 214 };
    int expected = -10;
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// ����Ψһ�����֣��������ֶ��Ǹ���
void Test5()
{
    int numbers[] = { -209, 3467, -209, -209 };
    int expected = 3467;
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// �ظ�������������Ҳ�и���
void Test6()
{
    int numbers[] = { 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
    int expected = 1023;
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), expected);
}

// �������ֶ��Ǹ���
void Test7()
{
    int numbers[] = { -1024, -1024, -1024, -1023 };
    int expected = -1023;
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), expected);
}

// Ψһ��������0
void Test8()
{
    int numbers[] = { -23, 0, 214, -23, 214, -23, 214 };
    int expected = 0;
    Test("Test8", numbers, sizeof(numbers) / sizeof(int), expected);
}

// ����Ψһ�����֣��������ֶ���0
void Test9()
{
    int numbers[] = { 0, 3467, 0, 0, 0, 0, 0, 0 };
    int expected = 3467;
    Test("Test9", numbers, sizeof(numbers) / sizeof(int), expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
