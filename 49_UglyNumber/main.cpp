#include <iostream>

#include <cstdio>

// ====================算法1的代码====================
bool IsUgly(int number)
{
    while(number % 2 == 0)
        number /= 2;
    while(number % 3 == 0)
        number /= 3;
    while(number % 5 == 0)
        number /= 5;

    return (number == 1) ? true : false;
}

int GetUglyNumber_Solution1(int index)
{
    if(index <= 0)
        return 0;

    int number = 0;
    int uglyFound = 0;
    while(uglyFound < index)
    {
        ++number;

        if(IsUgly(number))
            ++uglyFound;
    }

    return number;
}

// ====================算法2的代码====================
int Min(int number1, int number2, int number3);

int GetUglyNumber_Solution2(int index)
{
    if(index<=0)return 0;
    int * arrugly = new int [index];
    arrugly[0] = 1;
    int nextindex = 1;
    int *ugly2 = arrugly;
    int *ugly3 = arrugly;
    int *ugly5 = arrugly;


    while(nextindex
          <index){
        int minnum = Min(*ugly2*2,*ugly3*3,*ugly5*5);
        arrugly[nextindex] = minnum;
        if(*ugly2*2==arrugly[nextindex])
            ++ugly2;
        if(*ugly3*3==arrugly[nextindex])
            ++ugly3;
        if(*ugly5*5==arrugly[nextindex])
            ++ugly5;
        nextindex++;
    }
    int res = arrugly[index-1];
    delete [] arrugly;
    return res;
}

int Min(int number1, int number2, int number3)
{
    int minnum;
    minnum = number1<=number2?number1:number2;
    minnum = minnum<=number3?minnum:number3;
    return minnum;
}

// ====================测试代码====================
void Test(int index, int expected)
{
    if(GetUglyNumber_Solution1(index) == expected)
        printf("solution1 passed\n");
    else
        printf("solution1 failed\n");

    if(GetUglyNumber_Solution2(index) == expected)
        printf("solution2 passed\n");
    else
        printf("solution2 failed\n");
}

int main(int argc, char* argv[])
{
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}
