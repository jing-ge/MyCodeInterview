#include <iostream>

using namespace std;


#include <string>
#include <iostream>
#include <map>
#include <vector>

// 方法一：蛮力法
bool hasDuplication(const std::string& str, int position[]);

int longestSubstringWithoutDuplication_1(const std::string& str)
{
    int longest = 0;
    int* position = new int[26];
    for(int start = 0; start < str.length(); ++start)
    {
        for(int end = start; end < str.length(); ++end)
        {
            int count = end - start + 1;
            const std::string& substring = str.substr(start, count);
            if(!hasDuplication(substring, position))
            {
                if(count > longest)
                    longest = count;
            }
            else
                break;

        }
    }

    delete[] position;
    return longest;
}

bool hasDuplication(const std::string& str, int position[])
{
    for(int i = 0; i < 26; ++i)
        position[i] = -1;

    for(int i = 0; i < str.length(); ++i)
    {
        int indexInPosition = str[i] - 'a';
        if(position[indexInPosition] >= 0)
            return true;

        position[indexInPosition] = indexInPosition;
    }

    return false;
}

// 方法一：动态规划
int longestSubstringWithoutDuplication_2(const std::string& str)
{

    if(str.length()<=0)return 0;
    map<char,int> mymap;
    vector<int> dp(str.length(),0);
    map <char, int>::iterator iter;
    dp[0]=1;
    mymap[str[0]]=0;
    int maxlen = 1;
    for(int i=1;i<str.length();i++){
        iter = mymap.find(str[i]);
        if(iter==mymap.end()){
            mymap[str[i]]=i;
            dp[i] = dp[i-1]+1;
            if(dp[i]>maxlen)maxlen = dp[i];
        }else{
            int d = i-mymap[str[i]];
            mymap[str[i]]=i;;
            if(d<=dp[i-1]){
                dp[i] = d;
            }else{
                dp[i] = dp[i-1]+1;
            }
            if(dp[i]>maxlen)maxlen = dp[i];
        }
    }
    return maxlen;
}

// ====================测试代码====================
void testSolution1(const std::string& input, int expected)
{
    int output = longestSubstringWithoutDuplication_1(input);
    if(output == expected)
        std::cout << "Solution 1 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 1 FAILED, with input: " << input << std::endl;
}

void testSolution2(const std::string& input, int expected)
{
    int output = longestSubstringWithoutDuplication_2(input);
    if(output == expected)
        std::cout << "Solution 2 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 2 FAILED, with input: " << input << std::endl;
}

void test(const std::string& input, int expected)
{
    testSolution1(input, expected);
    testSolution2(input, expected);
}

void test1()
{
    const std::string input = "abcacfrar";
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const std::string input = "acfrarabc";
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const std::string input = "arabcacfr";
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const std::string input = "aaaa";
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const std::string input = "abcdefg";
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const std::string input = "aaabbbccc";
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const std::string input = "abcdcba";
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const std::string input = "abcdaef";
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const std::string input = "a";
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const std::string input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char* argv[])
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
    test10();

    return 0;
}
