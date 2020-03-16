#include <iostream>
#include <cstdio>
using namespace std;

// ====================方法1：递归====================
long long Fibonacci_Solution1(unsigned int n)
{
    long long f0 = 0;
    long long f1 = 1;
    if(n==0) return f0;
    if(n==1) return f1;
    return Fibonacci_Solution1(n-1)+Fibonacci_Solution1(n-2);
}

// ====================方法2：循环====================
long long Fibonacci_Solution2(unsigned n)
{
    long long f0 = 0;
    long long f1 = 1;
    if(n==0) return f0;
    if(n==1) return f1;
    long long fn;
    for(int i = 2;i<=n;i++)
    {
        fn = f0+f1;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}

// ====================方法3：基于矩阵乘法====================
#include <cassert>

struct Matrix2By2
{
    Matrix2By2 (long long m00,long long m01,long long m10,long long m11)
    :m_00(m00),m_01(m01),m_10(m10),m_11(m11)
    {
    }
    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

Matrix2By2 MatrixMul(const Matrix2By2& M1,const Matrix2By2& M2)
{
    return Matrix2By2(M1.m_00*M2.m_00 + M1.m_01* M2.m_10,M1.m_00*M2.m_01 + M1.m_01* M2.m_11,
                      M1.m_10*M2.m_00 + M1.m_11* M2.m_10,M1.m_10*M2.m_01 + M1.m_11* M2.m_11);
}

Matrix2By2 MatrixPow(int n)
{
    Matrix2By2 matrix = Matrix2By2(1,1,1,0);
    if(n==1)
    {
      matrix = Matrix2By2(1,1,1,0);
    }
    else if(n%2==0)
    {
        matrix = MatrixPow(n/2);
        matrix = MatrixMul(matrix,matrix);
    }
    else
    {
        matrix = MatrixPow(n/2);
        matrix = MatrixMul(matrix,matrix);
        matrix = MatrixMul(matrix,Matrix2By2(1,1,1,0));
    }
    return matrix;
}


long long Fibonacci_Solution3(unsigned int n)
{
    long long f0 = 0;
    long long f1 = 1;
    if(n==0) return f0;
    if(n==1) return f1;
    Matrix2By2 matrix = MatrixPow(n-1);
    return matrix.m_00;
}



// ====================测试代码====================
void Test(int n, int expected)
{
    if(Fibonacci_Solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if(Fibonacci_Solution2(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

    if(Fibonacci_Solution3(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);
}
int main()
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);
    return 0;
}
