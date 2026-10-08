#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
using namespace std;

constexpr int STK_MAX = 1000;

class Stack
{
    int _top;
    char buf[STK_MAX];

public:
    Stack()
    {
        _top = -1;
    }

    void push(char c)
    {
        if (!isFull())
        {
            _top++;
            buf[_top] = c;
        }
    }
    
    char pop()
    {
        char c = buf[_top];
        _top--;
        return c;
    }

    char top()
    {
        return buf[_top];
    }

    bool isEmpty()
    {
        return _top == -1;
    }

    bool isFull()
    {
        return _top == STK_MAX -1;
    }
};

void push_all(Stack & stk, string line)
{
    for (char ch : line)
        stk.push[ch];
}
void pop_all(Stack & stk)
{
    while (!stk.isEmpty())
        cout << stk.pop();
    cout << endl;
}

#endif