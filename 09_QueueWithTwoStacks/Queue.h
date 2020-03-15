#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


#pragma once
#include <stack>
#include <exception>
#include <queue>

using namespace std;

template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{

}

template <typename T> CQueue<T>::~CQueue(void)
{

}


template <typename T> void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}
template <typename T> T CQueue<T>::deleteHead()
{
    int s2 = stack2.size();
    if(s2<=0)
    {
           while(stack1.size()>0)
           {
               T& tmp = stack1.top();
               stack2.push(tmp);
               stack1.pop();
           }
    }
    if(stack2.size() == 0)
        throw "queue is empty";
    T& res = stack2.top();
    stack2.pop();
    return res;
}

template <typename T> class CStack
{
public:
    CStack(void);
    ~CStack(void);

    void appendTail(const T& node);
    T deleteTail();
private:
    queue<T> queue1;
    queue<T> queue2;
};

template <typename T> CStack<T>::CStack(void)
{

}

template <typename T> CStack<T>::~CStack(void)
{

}
template <typename T> void CStack<T>::appendTail(const T& node)
{
    queue1.push(node);
}

template <typename T> T CStack<T>::deleteTail()
{

    while(queue1.size()>1)
    {
        T& tmp = queue1.front();
        queue2.push(tmp);
        queue1.pop();
    }
    T& res = queue1.front();
    queue1.pop();
    while(queue2.size()>0)
    {
        T& tmp2 = queue2.front();
        queue1.push(tmp2);
        queue2.pop();
    }
    return res;
}

#endif // QUEUE_H_INCLUDED
