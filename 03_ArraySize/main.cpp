#include <iostream>
#include <cstdio>

using namespace std;

int GetSize(int data[])
{
    return sizeof(data);
}

int Test()
{
    int data1[] = {1,2,3,4,5};
    int size1 = sizeof(data1);
    //data1 是一个数组，sizeof(data1)是求数组的大小，5个整数一个整数4个字节，共20字节


    int *data2 = data1;
    int size2 = sizeof(data2);
    //data2 声明为指针，指向了data1的第一个数字，但本质还是一个指针，任意指针与系统位数有关，输出为4

    int size3 = GetSize(data1);
    //在C、C++中当数组作为函数的参数进行传递的时候，数组就自动退化为同类型指针，因此在size3中
    //尽管参数被声明为数组变量，但是会退化为指针，结果任然是4个字节

    printf("%d,%d,%d",size1,size2,size3);
}

int main()
{
    cout << "Hello world!" << endl;
    Test();
    return 0;
}
