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
//�ҵĽ��
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
//�ٷ���
void ReplaceBlank2(char str[], int length)
{
    if(str == nullptr && length <= 0)
        return;

    /*originalLength Ϊ�ַ���str��ʵ�ʳ���*/
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

    /*newLength Ϊ�ѿո��滻��'%20'֮��ĳ���*/
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
// ====================���Դ���====================
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

// �ո��ھ����м�
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// ����nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
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
