#include <iostream>
#include <string>>
using namespace std;


int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
int getDigitSum(int number);

int movingCount(int threshold, int rows, int cols)
{
    if(threshold<0||rows<=0||cols<=0)return 0;

    bool* visit = new bool[rows*cols];
    for(int i = 0;i<rows*cols;i++)
    {
        visit[i] = false;
    }
    int countnum = movingCountCore(threshold,rows,cols,0,0,visit);
    delete [] visit;
    return countnum;
}

int movingCountCore(int threshold, int rows, int cols, int row,
    int col, bool* visited)
{
    int countnum = 0;
    if(check(threshold,rows,cols,row,col,visited))
    {
        visited[row*cols+col] = true;
        countnum = 1 + movingCountCore(threshold,rows,cols,row-1,col,visited)
                     + movingCountCore(threshold,rows,cols,row+1,col,visited)
                     + movingCountCore(threshold,rows,cols,row,col-1,visited)
                     + movingCountCore(threshold,rows,cols,row,col+1,visited);
    }
    return countnum;
}

bool check(int threshold, int rows, int cols, int row, int col,
    bool* visited)
{
    if(col>=0&&col<cols&&row>=0&&row<rows&&!visited[row*cols+col])
    {
        string s1 = to_string(row);
        string s2 = to_string(col);
        string s3 = s1+s2;
        int res = 0;
        for(int i = 0;i<s3.size();i++)
        {
            res+=(int) (s3[i]-'0');
        }
        if(res<=threshold)
        {
            return true;
        }
        return false;
    }
    return false;


}

// ====================���Դ���====================
void test(char* testName, int threshold, int rows, int cols, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// ������ж���
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// ������ж���
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// ����ֻ��һ�У��������ܵ������з���
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// ����ֻ��һ�У��������ܵ������з���
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// ����ֻ��һ��һ��
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// ����ֻ��һ��һ��
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// �����˲��ܽ�������һ������
void test9()
{
    test("Test9", -10, 10, 10, 0);
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
    return 0;
}
