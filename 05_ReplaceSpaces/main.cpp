#include <iostream>
#include <cstring>
using namespace std;

void str()
{
    char str1[] = "hello world";
    char str2[] = "hello world";
    char* str3 = "hello world";
    char* str4 = "hello world";

    if(str1 == str2)
    {
        cout<<"str1 and str2 are same\n";
    }else
    {
        cout<<"str1 and str2 are not same\n";
    }

    if(str3 == str4)
    {
        cout<<"str3 and str4 are same\n";
    }else
    {
        cout<<"str3 and str4 are not same\n";
    }
}
//我的解答
void ReplaceBlank(char str[], int length)
{
    if(str == nullptr && length <= 0)
        return;
    int oldlength = 1;
    int num = 0;
    int i = 0;

    while(str[i] != '\0')
    {
        oldlength++;
        if (str[i]==' ')
        {
            num++;
        }
        i++;
    }
    int newlength = oldlength + num*2;
    if(newlength > length)
        return;
    int p1 = oldlength;
    int p2 = newlength;
    while(p1!=-1)
    {
        if(str[p1]!=' ')
        {
            str[p2] = str[p1];
            p2--;
            p1--;
        }else
        {
            str[p2] = '0';
            p2--;
            str[p2] = '2';
            p2--;
            str[p2] = '%';
            p2--;
            p1--;

        }
    }
}
//官方答案
void ReplaceBlank2(char str[], int length)
{
    if(str == nullptr && length <= 0)
        return;

    /*originalLength 为字符串str的实际长度*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++ originalLength;

        if(str[i] == ' ')
            ++ numberOfBlank;

        ++ i;
    }

    /*newLength 为把空格替换成'%20'之后的长度*/
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(str[indexOfOriginal] == ' ')
        {
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        else
        {
            str[indexOfNew --] = str[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
}
// ====================测试代码====================
void Test(char* testName, char str[], int length, char expected[])
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main()
{
    cout<<"str test"<<endl;
    str();
    cout<<"----------"<<endl;
    cout<<"Replace space test"<<endl;
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
