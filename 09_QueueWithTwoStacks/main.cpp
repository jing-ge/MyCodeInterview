#include <iostream>
#include "Queue.h"

using namespace std;




// ====================≤‚ ‘¥˙¬Î====================
void Test(char actual, char expected)
{
    printf("actual: %c\n",actual);
     printf("expected: %c\n",expected);
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{

    printf("TEST for myQueue start:\n");
    CQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    Test(head, 'a');

    head = queue.deleteHead();
    Test(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    Test(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    Test(head, 'd');

    head = queue.deleteHead();
    Test(head, 'e');
    printf("TEST for myQueue end.\n");
    printf("----------------------------\n");
    printf("TEST for myStack start:\n");
    CStack<char> mystack;
    mystack.appendTail('a');
    mystack.appendTail('b');
    mystack.appendTail('c');
    char tail = mystack.deleteTail();
    Test(tail,'c');

    tail = mystack.deleteTail();
    Test(tail,'b');

    tail = mystack.deleteTail();
    Test(tail,'a');
    printf("TEST for myStack end.\n");
    return 0;
}
