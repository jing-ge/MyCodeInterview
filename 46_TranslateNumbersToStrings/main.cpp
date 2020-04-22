
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

int GetTranslationCount(const string& number);

int GetTranslationCount(int number)
{
    if(number<0)return 0;
    string strnum = to_string(number);
    int res = GetTranslationCount(strnum);
    return res;
}

int GetTranslationCount(const string& number)
{
   int length = number.length();
   if(length==1)return 1;
   if(length==2){
        int num = stoi(number);
        if(num>=10&&num<=25){
            return 2;
        }
        return 1;
   }
   int* counts = new int[length];
   counts[length-1] = 1;
   counts[length-2] = (stoi(number.substr(length-2,2))>=10&&stoi(number.substr(length-2,2))<=25)?2:1;
   for(int i = length-3;i>=0;i--){
        int dig1 = number[i]-'0';
        int dig2 = number[i+1]-'0';
        int covert = dig1*10+dig2;
        if(covert>=10&&covert<=25){
            counts[i] = counts[i+1]+counts[i+2];
        }else{
            counts[i] = counts[i+1];
        }
   }
   return counts[0];
}

// ====================²âÊÔ´úÂë====================
void Test(const string& testName, int number, int expected)
{
    if(GetTranslationCount(number) == expected)
        cout << testName << " passed." << endl;
    else
        cout << testName << " FAILED." << endl;
}

void Test1()
{
    int number = 0;
    int expected = 1;
    Test("Test1", number, expected);
}

void Test2()
{
    int number = 10;
    int expected = 2;
    Test("Test2", number, expected);
}

void Test3()
{
    int number = 125;
    int expected = 3;
    Test("Test3", number, expected);
}

void Test4()
{
    int number = 126;
    int expected = 2;
    Test("Test4", number, expected);
}

void Test5()
{
    int number = 426;
    int expected = 1;
    Test("Test5", number, expected);
}

void Test6()
{
    int number = 100;
    int expected = 2;
    Test("Test6", number, expected);
}

void Test7()
{
    int number = 101;
    int expected = 2;
    Test("Test7", number, expected);
}

void Test8()
{
    int number = 12258;
    int expected = 5;
    Test("Test8", number, expected);
}

void Test9()
{
    int number = -100;
    int expected = 0;
    Test("Test9", number, expected);
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

    return 0;
}
