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
    //data1 ��һ�����飬sizeof(data1)��������Ĵ�С��5������һ������4���ֽڣ���20�ֽ�


    int *data2 = data1;
    int size2 = sizeof(data2);
    //data2 ����Ϊָ�룬ָ����data1�ĵ�һ�����֣������ʻ���һ��ָ�룬����ָ����ϵͳλ���йأ����Ϊ4

    int size3 = GetSize(data1);
    //��C��C++�е�������Ϊ�����Ĳ������д��ݵ�ʱ��������Զ��˻�Ϊͬ����ָ�룬�����size3��
    //���ܲ���������Ϊ������������ǻ��˻�Ϊָ�룬�����Ȼ��4���ֽ�

    printf("%d,%d,%d",size1,size2,size3);
}

int main()
{
    cout << "Hello world!" << endl;
    Test();
    return 0;
}
