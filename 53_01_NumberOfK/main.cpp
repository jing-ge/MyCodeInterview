#include <iostream>

using namespace std;

#include <cstdio>

int GetFirstK(const int* data, int length, int k, int start, int end);
int GetLastK(const int* data, int length, int k, int start, int end);

int GetNumberOfK(const int* data, int length, int k)
{
    int number = 0;
	if(data==nullptr||length<=0)return number;
	int firstk = GetFirstK(data,length,k,0,length-1);
	int lastk = GetLastK(data,length,k,0,length-1);
	if(firstk>-1&& lastk>-1){
        return lastk-firstk+1;
	}
	return 0;
}

// �ҵ������е�һ��k���±ꡣ��������в�����k������-1
int GetFirstK(const int* data, int length, int k, int start, int end)
{
    if(start>end)return -1;
    int mid = (start+end)/2;
    int middata = data[mid];
    if(middata==k){
        if(mid>0&&data[mid-1]!=k||mid==0){
            return mid;
        }
        end = mid-1;
    }else if(middata>k){
        end = mid-1;
    }else{
        start = mid+1;
    }
    return GetFirstK(data,length,k,start,end);
}

// �ҵ����������һ��k���±ꡣ��������в�����k������-1
int GetLastK(const int* data, int length, int k, int start, int end)
{
    if(start>end)return -1;
    int mid = (start+end)/2;
    int middata = data[mid];
    if(middata==k){
        if(mid<length-1&&data[mid+1]!=k||mid==(length-1)){
            return mid;
        }else{
            start = mid+1;
        }
    }else if(middata>k){
        end = mid-1;
    }else{
        start = mid+1;
    }
    return GetLastK(data,length,k,start,end);
}

// ====================���Դ���====================
void Test(const char* testName, int data[], int length, int k, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result = GetNumberOfK(data, length, k);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// ���ҵ����ֳ�����������м�
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ��������������Ŀ�ͷ
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ��������������Ľ�β
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ����ֲ�����
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// ���ҵ����ֱȵ�һ�����ֻ�С��������
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// ���ҵ����ֱ����һ�����ֻ��󣬲�����
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// �����е����ִ�ͷ��β���ǲ��ҵ�����
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// �����е����ִ�ͷ��βֻ��һ���ظ������֣����ǲ��ҵ�����
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// ������ֻ��һ�����֣��ǲ��ҵ�����
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// ������ֻ��һ�����֣����ǲ��ҵ�����
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// ³���Բ��ԣ������ָ��
void Test11()
{
    Test("Test11", nullptr, 0, 0, 0);
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
    Test10();
    Test11();

    return 0;
}