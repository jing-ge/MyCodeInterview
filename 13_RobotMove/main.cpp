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

// ====================测试代码====================
void test(char* testName, int threshold, int rows, int cols, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 方格多行多列
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
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
