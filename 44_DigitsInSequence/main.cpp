#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

using namespace std;

int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);

int digitAtIndex(int index)
{
	if(index<0)return -1;
	int digit;
	for(digit = 1;;digit++){
        long number = countOfIntegers(digit);
        if(number>=index){
            break;
        }
	}
	int cha = index-countOfIntegers(digit-1);
	int beginnum = beginNumber(digit);
	int shang = cha/digit;
	int yu = cha%digit;
	int res = beginnum+shang;
	string r;
	r = to_string(res);
	return r[yu]-'0';

}

int countOfIntegers(int digit)
{
    int res = 0;
    for(int i=1;i<=digit;i++){
        if(i==1)res+=10;
        else res+= 9*beginNumber(i)*i;
    }
    return res;
}


int beginNumber(int digit)
{
    if(digit==1)return 0;
    int res = 10;
    for(int i=1;i<digit-1;i++){
        res *=10;
    }
    return res;
}

// ====================测试代码====================
void test(const char* testName, int inputIndex, int expectedOutput)
{
	if(digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}


int main()
{
    cout<<countOfIntegers(8)<<endl;
    cout<<digitAtIndex(800000000)<<endl;
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // 数字99的最后一位，9
	test("Test6", 190, 1);  // 数字100的第一位，1
	test("Test7", 1000, 3); // 数字370的第一位，3
	test("Test8", 1001, 7); // 数字370的第二位，7
	test("Test9", 1002, 0); // 数字370的第三位，0
    cout<<digitAtIndex(800000000);

	return 0;
}
