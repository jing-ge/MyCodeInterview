
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

vector<int> maxInWindows(const vector<int>& nums, unsigned int k)
{
    vector<int> res;
    deque<int> deq;
    for(int i=0;i<nums.size();i++){
        while(!deq.empty()&&nums[i]>=nums[deq.back()])
            deq.pop_back();
        int cha = i-k;
        while(!deq.empty()&& deq.front()<=cha)
            deq.pop_front();
        deq.push_back(i);
        if(i>=k-1)res.push_back(nums[deq.front()]);
    }
    return res;
}

// ====================测试代码====================
void Test(const char* testName, const vector<int>& num, unsigned int size, const vector<int>& expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    vector<int> result = maxInWindows(num, size);

    vector<int>::const_iterator iterResult = result.begin();
    vector<int>::const_iterator iterExpected = expected.begin();
    while(iterResult < result.end() && iterExpected < expected.end())
    {
        if(*iterResult != *iterExpected)
            break;

        ++iterResult;
        ++iterExpected;
    }

    if(iterResult == result.end() && iterExpected == expected.end())
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void Test1()
{
    int num[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = { 4, 4, 6, 6, 6, 5 };
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 3;

    Test("Test1", vecNumbers, size, vecExpected);
}

void Test2()
{
    int num[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = { 3, 3, 5, 5, 6, 7 };
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 3;

    Test("Test2", vecNumbers, size, vecExpected);
}

// 输入数组单调递增
void Test3()
{
    int num[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = { 7, 9, 11, 13, 15 };
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 4;

    Test("Test3", vecNumbers, size, vecExpected);
}

// 输入数组单调递减
void Test4()
{
    int num[] = { 16, 14, 12, 10, 8, 6, 4 };
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = { 16, 14, 12 };
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 5;

    Test("Test4", vecNumbers, size, vecExpected);
}

// 滑动窗口的大小为1
void Test5()
{
    int num[] = { 10, 14, 12, 11 };
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = { 10, 14, 12, 11 };
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 1;

    Test("Test5", vecNumbers, size, vecExpected);
}

// 滑动窗口的大小等于数组的长度
void Test6()
{
    int num[] = { 10, 14, 12, 11 };
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = { 14 };
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 4;

    Test("Test6", vecNumbers, size, vecExpected);
}

// 滑动窗口的大小为0
void Test7()
{
    int num[] = { 10, 14, 12, 11 };
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    vector<int> vecExpected;

    unsigned int size = 0;

    Test("Test7", vecNumbers, size, vecExpected);
}

// 滑动窗口的大小大于输入数组的长度
void Test8()
{
    int num[] = { 10, 14, 12, 11 };
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    vector<int> vecExpected;

    unsigned int size = 5;

    Test("Test8", vecNumbers, size, vecExpected);
}

// 输入数组为空
void Test9()
{
    vector<int> vecNumbers;
    vector<int> vecExpected;

    unsigned int size = 5;

    Test("Test9", vecNumbers, size, vecExpected);
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
