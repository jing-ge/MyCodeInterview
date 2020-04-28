#include <iostream>

using namespace std;


#include <cstdio>
int mergesort(int *data,int l,int r){
    int sum=0;
    if(l==r)return 0;
    int m = (l+r)/2;
    sum+=mergesort(data,l,m);
    sum+=mergesort(data,m+1,r);
    int *cdata = new int[r-l+1];
    //merge
    int lp=l,rp=m+1,s=0;
    while(lp<=m&&rp<=r){
        if(data[lp]<=data[rp]){
            cdata[s]=data[lp];
            lp++;
        }else{
            cdata[s]=data[rp];
            sum+=m-lp+1;
            rp++;
        }
        s++;
    }
    while(lp<=m){
        cdata[s] = data[lp];
        lp++;
        s++;
    }
    while(rp<=r){
        cdata[s]=data[rp];
        rp++;
        s++;
    }
    for(int i=l;i<=r;i++){
        data[i] = cdata[i-l];
    }
    delete []cdata;
    return sum;
}
int InversePairs(int* data, int length){
    int sum=0;
//    cout<<endl;
    if(length<=0||data==nullptr)return 0;
//    for(int i=0;i<length;i++){
//        cout<<data[i]<<"\t";
//    }
//    cout<<endl;
    sum = mergesort(data,0,length-1);
//    for(int i=0;i<length;i++){
//        cout<<data[i]<<"\t";
//    }
//    cout<<endl;
    cout<<"sum:"<<sum<<endl;
    return sum;
}


//
//int InversePairsCore(int* data, int* copy, int start, int end);
//
//int InversePairs(int* data, int length)
//{
//    if(data == nullptr || length < 0)
//        return 0;
//
//    int* copy = new int[length];
//    for(int i = 0; i < length; ++i)
//        copy[i] = data[i];
//
//    int count = InversePairsCore(data, copy, 0, length - 1);
//    delete[] copy;
//
//    return count;
//}
//
//int InversePairsCore(int* data, int* copy, int start, int end)
//{
//    if(start == end)
//    {
//        copy[start] = data[start];
//        return 0;
//    }
//
//    int length = (end - start) / 2;
//
//    int left = InversePairsCore(copy, data, start, start + length);
//    int right = InversePairsCore(copy, data, start + length + 1, end);
//
//    // i��ʼ��Ϊǰ������һ�����ֵ��±�
//    int i = start + length;
//    // j��ʼ��Ϊ�������һ�����ֵ��±�
//    int j = end;
//    int indexCopy = end;
//    int count = 0;
//    while(i >= start && j >= start + length + 1)
//    {
//        if(data[i] > data[j])
//        {
//            copy[indexCopy--] = data[i--];
//            count += j - start - length;
//        }
//        else
//        {
//            copy[indexCopy--] = data[j--];
//        }
//    }
//
//    for(; i >= start; --i)
//        copy[indexCopy--] = data[i];
//
//    for(; j >= start + length + 1; --j)
//        copy[indexCopy--] = data[j];
//
//    return left + right + count;
//}

// ====================���Դ���====================
void Test(char* testName, int* data, int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(InversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int data[] = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// �ݼ���������
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// ������������
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// ������ֻ��һ������
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// ������ֻ���������֣���������
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// ������ֻ���������֣��ݼ�����
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// ����������ȵ�����
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
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

    return 0;
}
