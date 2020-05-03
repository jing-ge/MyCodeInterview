#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
#include <exception>

using namespace std;

template<typename T> class QueueWithMax
{
public:
    QueueWithMax()
    {
    }

    void push_back(T number)
    {
       while(!deq.empty()&&number>=data[deq.back()])
         deq.pop_back();

       if(head==-1){
        head++;
        tail++;
       }else{
        tail++;
       }
        deq.push_back(tail);
        data.push_back(number);
    }

    void pop_front()
    {
        if(deq.empty())return;
        head++;
        while(!deq.empty()&&deq.front()<head)
         deq.pop_front();

    }

    T max() const
    {
        if(!deq.empty())return data[deq.front()];
    }

private:
    vector<T> data;
    deque<int> deq;
    int head=-1;
    int tail=-1;
};

// ====================≤‚ ‘¥˙¬Î====================
void Test(const char* testName, const QueueWithMax<int>& queue, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(queue.max() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    QueueWithMax<int> queue;
    // {2}
    queue.push_back(2);
    Test("Test1", queue, 2);

    // {2, 3}
    queue.push_back(3);
    Test("Test2", queue, 3);

    // {2, 3, 4}
    queue.push_back(4);
    Test("Test3", queue, 4);

    // {2, 3, 4, 2}
    queue.push_back(2);
    Test("Test4", queue, 4);

    // {3, 4, 2}
    queue.pop_front();
    Test("Test5", queue, 4);

    // {4, 2}
    queue.pop_front();
    Test("Test6", queue, 4);

    // {2}
    queue.pop_front();
    Test("Test7", queue, 2);

    // {2, 6}
    queue.push_back(6);
    Test("Test8", queue, 6);

    // {2, 6, 2}
    queue.push_back(2);
    Test("Test9", queue, 6);

    // {2, 6, 2, 5}
    queue.push_back(5);
    Test("Test9", queue, 6);

    // {6, 2, 5}
    queue.pop_front();
    Test("Test10", queue, 6);

    // {2, 5}
    queue.pop_front();
    Test("Test11", queue, 5);

    // {5}
    queue.pop_front();
    Test("Test12", queue, 5);

    // {5, 1}
    queue.push_back(1);
    Test("Test13", queue, 5);

    return 0;
}
