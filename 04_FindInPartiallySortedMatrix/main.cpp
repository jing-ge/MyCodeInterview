#include <iostream>

using namespace std;
#include <cstdio>


//ȫ������ ʱ�临�Ӷ�ΪO��n2��
bool Find1(int* matrix, int rows, int columns, int number)
{
    bool res = false;
    for(int i = 0;i<(columns*rows);i++)
    {
        if (matrix[i]==number)
        {
            res = true;
            break;
        }
    }
    return res;
}

int getIndex(int row,int col,int i,int j)
{
    return (i-1)*col + j -1;
}
//�����Ͻǽ��п�ʼ�������ظ�����
bool Find2(int* matrix, int rows, int columns, int number)
{
    bool res = false;
    if(matrix != nullptr && rows>0 && columns>0)
    {
        int i = 1;
        int j = columns;
        while(i<= rows&& j>=1)
        {
            int idx = getIndex(rows,columns,i,j);
            if(matrix[idx]==number)
            {
                res = true;
                break;
            }else if(matrix[idx]>number)
            {
                j--;
            }else
            {
                i++;
            }
        }
    }
    return res;
}

//�����½ǽ��п�ʼ�������ظ�����
bool Find3(int* matrix, int rows, int columns, int number)
{
    bool res = false;
    if(matrix != nullptr && rows>0 && columns>0)
    {
        int i = rows;
        int j = 1;
        while(j<= columns&& i>=1)
        {
            int idx = getIndex(rows,columns,i,j);
            if(matrix[idx]==number)
            {
                res = true;
                break;
            }else if(matrix[idx]>number)
            {
                i--;
            }else
            {
                j++;
            }
        }
    }
    return res;
}
// ====================���Դ���====================
void Test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    bool result = Find3(matrix, rows, columns, number);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�����������
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С������
void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������������
void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С�����ֻ�С
void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ������������������ֻ���
void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// ³���Բ��ԣ������ָ��
void Test7()
{
    Test("Test7", nullptr, 0, 0, 16, false);
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

    return 0;
}
