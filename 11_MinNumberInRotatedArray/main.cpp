#include <iostream>

using namespace std;

#include <cstdio>
#include <exception>

int MinInOrder(int* numbers, int index1, int index2);

int MinInOrder(int* numbers, int index1, int index2)
{
    int res = 1000000;
    for(int i = index1;i<=index2;i++)
    {
        if(res>numbers[i])
        {
            res = numbers[i];
        }
    }
    return res;
}

int Min(int* numbers, int length)
{
    if(numbers==nullptr || length<=0)
        return 0;
    if(length==1)
    {
        return numbers[0];
    }
    int l = 0;
    int r = length-1;
    while(l<r)
    {
        int mid = (l+r)/2;
        if((r-l)==1)
        {
            return numbers[l]<numbers[r]?numbers[l]:numbers[r];
        }
        if(numbers[l]<=numbers[mid]&& numbers[mid]<=numbers[r])
        {
            if(numbers[l]==numbers[mid]&& numbers[mid]==numbers[r]){
                return MinInOrder(numbers,l,r);
            }
            return numbers[l];
        }

        if(numbers[mid]>numbers[r])
        {
            l = mid+1;
        }
        else
        {
            r = mid;
        }
    }
    return numbers[l];

}
// ====================测试代码====================
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == nullptr)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}
int main()
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    int array7[] = { 2 ,0,1,1,1};
    Test(array7, sizeof(array7) / sizeof(int), 0);

    int array8[] = {1,2,1};
    Test(array8, sizeof(array8) / sizeof(int), 0);

    // 输入nullptr
    Test(nullptr, 0, 0);

    return 0;
}
