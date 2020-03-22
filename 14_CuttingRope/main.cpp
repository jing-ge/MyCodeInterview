#include <iostream>
#include <cmath>

using namespace std;
// ====================��̬�滮====================
int maxProductAfterCutting_solution1(int length)
{
    if(length<2)return 0;
    if(length<=3)return length-1;
    int* dp = new int [length+1];
    dp[0]=0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4;i<=length;i++)
    {
        int maxlength = 0;
        for(int j = 1;j<=i/2;j++)
        {
            int tmp = dp[j]*dp[i-j];
            if(tmp>maxlength)maxlength = tmp;
        }
        dp[i] = maxlength;
    }
    return dp[length];
}

// ====================̰���㷨====================
int maxProductAfterCutting_solution2(int length)
{
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    int yu = length%3;
    int chu = length/3;
    int res = 0;
    if(yu==0)
    {
        res = pow(3,chu);
    }
    else if(yu==1)
    {
        res = pow(3,chu-1)*4;
    }
    else
    {
        res = pow(3,chu)*2;
    }
    return res;
}

// ====================���Դ���====================
void test(const char* testName, int length, int expected)
{
    int result1 = maxProductAfterCutting_solution1(length);
    if(result1 == expected)
        std::cout << "Solution1 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

    int result2 = maxProductAfterCutting_solution2(length);
    if(result2 == expected)
        std::cout << "Solution2 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void test1()
{
    int length = 1;
    int expected = 0;
    test("test1", length, expected);
}

void test2()
{
    int length = 2;
    int expected = 1;
    test("test2", length, expected);
}

void test3()
{
    int length = 3;
    int expected = 2;
    test("test3", length, expected);
}

void test4()
{
    int length = 4;
    int expected = 4;
    test("test4", length, expected);
}

void test5()
{
    int length = 5;
    int expected = 6;
    test("test5", length, expected);
}

void test6()
{
    int length = 6;
    int expected = 9;
    test("test6", length, expected);
}

void test7()
{
    int length = 7;
    int expected = 12;
    test("test7", length, expected);
}

void test8()
{
    int length = 8;
    int expected = 18;
    test("test8", length, expected);
}

void test9()
{
    int length = 9;
    int expected = 27;
    test("test9", length, expected);
}

void test10()
{
    int length = 10;
    int expected = 36;
    test("test10", length, expected);
}

void test11()
{
    int length = 50;
    int expected = 86093442;
    test("test11", length, expected);
}

int main()
{
     test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();

    return 0;
    return 0;
}
