#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

void Printarray(int array[],int length)
{
    for(int i=0; i<length; i++)
    {
        cout<<array[i]<<',';
    }
    cout<<endl;
}


//sort ���������ظ�����
//ʱ�䣺O��nlogn��
//�ռ䣺O��1��
bool duplicate1(int numbers[], int length, int* duplication)
{
    if (numbers == nullptr || length<=0)
        return false;

    for(int i=0; i<length; i++)
    {
        if(numbers[i]<=0 || numbers[i]>length)
            return false;
    }
    *duplication = length+1;
    sort(numbers,numbers+length);
    for(int i=0; i<length-1; i++)
    {
        if(numbers[i]==numbers[i+1])
        {
            *duplication = numbers[i];
        }
    }
    if(*duplication==length+1)
    {
        return false;
    }
    if(*duplication>=0 && *duplication<length)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//����hash�������ظ�����
//ʱ�䣺O��n��
//�ռ䣺O��n��
bool duplicate2(int numbers[], int length, int* duplication)
{
    if (numbers == nullptr || length<=0)
        return false;

    for(int i=0; i<length; i++)
    {
        if(numbers[i]<=0 || numbers[i]>length)
            return false;
    }
    *duplication = length+1;
    map<int,int> hashtable;
    for(int i=0; i<length; i++)
    {
        map<int,int>::iterator iter = hashtable.find(numbers[i]);
        if(iter==hashtable.end())
        {
            hashtable[numbers[i]]==1;
        }
        else
        {
            *duplication = numbers[i];
        }
    }
    if(*duplication==length+1)
    {
        return false;
    }
    if(*duplication>=0 && *duplication<length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//���ñ�������������hash������ظ�����
//ʱ�䣺O��n��
//�ռ䣺O��1��
bool duplicate3(int numbers[], int length, int* duplication)
{
    if (numbers == nullptr || length<=0)
        return false;

    for(int i=0; i<length; i++)
    {
        if(numbers[i]<=0 || numbers[i]>length)
            return false;
    }
    *duplication = length+1;
    for(int i=0; i<length; i++)
    {
        if(numbers[i]==i)
        {
            continue;
        }
        else
        {
            if(numbers[i]==numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            int tmp = numbers[numbers[i]];
            numbers[numbers[i]]==numbers[i];
            numbers[i] = tmp;
        }
    }
              if(*duplication==length+1)
    {
        return false;
    }
    if(*duplication>=0 && *duplication<length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate3(numbers, lengthNumbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// �ظ�����������������С������
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �ظ�����������������������
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �����д��ڶ���ظ�������
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// û���ظ�������
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// û���ظ�������
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// ��Ч������
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int main()
{
    cout << "03_01_Duplication" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}
