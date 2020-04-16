#include <iostream>

using namespace std;


#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

template<typename T> class DynamicArray
{
public:
    void Insert(T num){
        if(((minheap.size()+maxheap.size())&1)==0){
            if(maxheap.size()>0&&num<maxheap[0]){
                maxheap.push_back(num);
                push_heap(maxheap.begin(),maxheap.end(),less<T>());
                num = maxheap[0];
                pop_heap(maxheap.begin(),maxheap.end(),less<T>());
                maxheap.pop_back();
            }
            minheap.push_back(num);
            push_heap(minheap.begin(),minheap.end(),greater<T>());
        }else{
            if(minheap.size()>0&&num>minheap[0]){
                minheap.push_back(num);
                push_heap(minheap.begin(),minheap.end(),greater<T>());
                num = minheap[0];
                pop_heap(minheap.begin(),minheap.end(),greater<T>());
                minheap.pop_back();
            }
            maxheap.push_back(num);
            push_heap(maxheap.begin(),maxheap.end(),less<T>());
        }
    }
    T GetMedian(){
        int sizeheap = minheap.size()+maxheap.size();
//        cout<<"min:";
//        for(int i = 0;i<minheap.size();i++){
//            cout<<minheap[i]<<endl;
//        }
//        cout<<"max:";
//        for(int i = 0;i<maxheap.size();i++){
//            cout<<maxheap[i]<<endl;
//        }
        if(sizeheap==0){
            throw "No number!!";
        }
        T median;
        if((sizeheap&1)==0){
            median = (minheap[0]+maxheap[0])/2;
        }else{
            median = minheap[0];
        }
        return median;
    }
private:
    vector<T> minheap;
    vector<T> maxheap;
};

// ====================²âÊÔ´úÂë====================
void Test(char* testName, DynamicArray<double>& numbers, double expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(abs(numbers.GetMedian() - expected) < 0.0000001)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    DynamicArray<double> numbers;

//    printf("Test1 begins: ");
//    try
//    {
//        numbers.GetMedian();
//        printf("FAILED.\n");
//    }
//    catch(const exception&)
//    {
//        printf("Passed.\n");
//    }

    numbers.Insert(5);
    Test("Test2", numbers, 5);

    numbers.Insert(2);
    Test("Test3", numbers, 3.5);

    numbers.Insert(3);
    Test("Test4", numbers, 3);

    numbers.Insert(4);
    Test("Test6", numbers, 3.5);

    numbers.Insert(1);
    Test("Test5", numbers, 3);

    numbers.Insert(6);
    Test("Test7", numbers, 3.5);

    numbers.Insert(7);
    Test("Test8", numbers, 4);

    numbers.Insert(0);
    Test("Test9", numbers, 3.5);

    numbers.Insert(8);
    Test("Test10", numbers, 4);

    return 0;
}
