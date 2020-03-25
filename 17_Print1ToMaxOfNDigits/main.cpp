#include <iostream>

using namespace std;

#include <cstdio>
#include <memory>
#include <cstring>

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================����һ====================
void Print1ToMaxOfNDigits_1(int n)
{
    if(n<=0)return;
    char* number = new char[n+1];
    memset(number,'0',n);
    number[n] = '\0';
    while(Increment(number))
    {
        PrintNumber(number);
    }
    delete[]number;
}

// �ַ���number��ʾһ�����֣��� number������1
// ������ӷ�������򷵻�true������Ϊfalse
bool Increment(char* number)
{
    int jingwei = 0;
    int length = strlen(number);
    for(int i = length-1;i>=0;i--)
    {
        int iSum = number[i]-'0'+jingwei;
        if(i==length-1) iSum++;
        if(iSum>=10){
            if(i==0)
            {
                return false;
            }
            else
            {
                iSum -= 10;
                jingwei = 1;
                number[i] = '0'+iSum;
            }
        }
        else
        {
            jingwei = 0;
            number[i] = '0'+iSum;
            break;
        }
    }
    return true;
}

// ====================������====================
void Print1ToMaxOfNDigits_2(int n)
{
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if (index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

// ====================��������====================
// �ַ���number��ʾһ�����֣����������ɸ�0��ͷ
// ��ӡ��������֣������Կ�ͷ��0
void PrintNumber(char* number)
{
    int length = strlen(number);
    bool begin0 = true;
    for(int i = 0;i<length;i++)
    {
        if(number[i]!='0'&&begin0)
        {
            begin0 = false;
        }
        if(!begin0)
        {
            printf("%c",number[i]);
        }
    }
    printf("\t");
}

// ====================���Դ���====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

//    Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);

    printf("\nTest for %d ends.\n", n);
}

int main()
{
     Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);
    return 0;
}
