#include <iostream>

using namespace std;

#include <cstdio>
#include <list>

using namespace std;

// ====================方法1====================
int LastRemaining_Solution1(unsigned int n, unsigned int m)
{
    if(n<1||m<1)return -1;
    list<int> nums;
    for(int i=0;i<n;i++)
        nums.push_back(i);
    list<int>::iterator iter = nums.begin();
    while(nums.size()>1){
        for(int i=1;i<m;i++){
            iter++;
            if(iter==nums.end()){
                iter = nums.begin();
            }
        }
        list<int>::iterator next = ++iter;
        if(next==nums.end()){
            next = nums.begin();
        }
        iter--;
        nums.erase(iter);
        iter = next;
    }
    return *iter;
}

// ====================方法2====================
int LastRemaining_Solution2(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    int tmp = 0;
    for(int i=2;i<=n;i++)
        tmp = (tmp+m)%i;
    return tmp;
}

// ====================测试代码====================
void Test(const char* testName, unsigned int n, unsigned int m, int expected)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    if(LastRemaining_Solution1(n, m) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if(LastRemaining_Solution2(n, m) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void Test1()
{
    Test("Test1", 5, 3, 3);
}

void Test2()
{
    Test("Test2", 5, 2, 2);
}

void Test3()
{
    Test("Test3", 6, 7, 4);
}

void Test4()
{
    Test("Test4", 6, 6, 3);
}

void Test5()
{
    Test("Test5", 0, 0, -1);
}

void Test6()
{
    Test("Test6", 4000, 997, 1027);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
