#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
vector<double> twoSum(int n) {
    vector<double> res;
    int* dp[2];
    dp[0] = new int[6*n+1];
    dp[1] = new int[6*n+1];

    memset(dp[0],0,sizeof(dp[0]));
    memset(dp[1],0,sizeof(dp[1]));
    for(int i=0;i<6*n+1;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<6*n+1;i++){
        dp[1][i]=0;
    }

    for(int i=1;i<=6;i++){
        dp[0][i] = 1;
    }
    int flag = 0;
    for(int k=2;k<=n;k++){
        for(int r=0;r<6*n+1;r++){
                 dp[1-flag][r]=0;
        }
        for(int i=k;i<=6*k;i++){

            for(int j=1;j<=6&&j<=i;j++){
                dp[1-flag][i] += dp[flag][i-j];
            }
        }
        flag = 1-flag;
    }
    for(int i=0;i<6*n+1;i++){
        cout<<dp[0][i]<<'\t';
    }
    cout<<endl;
    for(int i=0;i<6*n+1;i++){
        cout<<dp[1][i]<<'\t';
    }
    cout<<endl;
    double total = pow(6.0,n);
    for(int i=n;i<=n*6;i++){
        double ratio = (double)dp[flag][i]/total;
        res.push_back(ratio);
    }
    return res;
}

#include <cstdio>
#include <math.h>

int g_maxValue = 6;

// ====================方法一====================
void Probability(int number, int* pProbabilities);
void Probability(int original, int current, int sum, int* pProbabilities);

void PrintProbability_Solution1(int number)
{
    if(number < 1)
        return;

    int maxSum = number * g_maxValue;
    int* pProbabilities = new int[maxSum - number + 1];
    for(int i = number; i <= maxSum; ++i)
        pProbabilities[i - number] = 0;

    Probability(number, pProbabilities);

    int total = pow((double)g_maxValue, number);
    for(int i = number; i <= maxSum; ++i)
    {
        double ratio = (double)pProbabilities[i - number] / total;
        printf("%d: %e\n", i, ratio);
    }

    delete[] pProbabilities;
}

void Probability(int number, int* pProbabilities)
{
    for(int i = 1; i <= g_maxValue; ++i)
        Probability(number, number, i, pProbabilities);
}

void Probability(int original, int current, int sum,
                 int* pProbabilities)
{
    if(current == 1)
    {
        pProbabilities[sum - original]++;
    }
    else
    {
        for(int i = 1; i <= g_maxValue; ++i)
        {
            Probability(original, current - 1, i + sum, pProbabilities);
        }
    }
}

// ====================方法二====================
void PrintProbability_Solution2(int number)
{
    if(number < 1)
        return;

    int* pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number + 1];
    pProbabilities[1] = new int[g_maxValue * number + 1];
    for(int i = 0; i < g_maxValue * number + 1; ++i)
    {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }

    int flag = 0;
    for (int i = 1; i <= g_maxValue; ++i)
        pProbabilities[flag][i] = 1;

    for (int k = 2; k <= number; ++k)
    {
        for(int i = 0; i < k; ++i)
            pProbabilities[1 - flag][i] = 0;

        for (int i = k; i <= g_maxValue * k; ++i)
        {
            pProbabilities[1 - flag][i] = 0;
            for(int j = 1; j <= i && j <= g_maxValue; ++j)
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
        }

        flag = 1 - flag;
    }

    double total = pow((double)g_maxValue, number);
    for(int i = number; i <= g_maxValue * number; ++i)
    {
        double ratio = (double)pProbabilities[flag][i] / total;
        printf("%d: %e\n", i, ratio);
    }

    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}

// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    printf("Test for solution1\n");
    PrintProbability_Solution1(n);

    printf("Test for solution2\n");
    PrintProbability_Solution2(n);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(4);

    Test(11);

    Test(0);

    return 0;
}
