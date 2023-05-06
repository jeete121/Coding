#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop()
    {
        int x = s1.top();
        s1.pop();
        return x;
    }
    int peek()
    {
        return s1.top();
    }
    bool empty()
    {
        int flag = 0;
        if (s1.empty())
            flag = 1;
        return flag;
    }
};

int main()
{
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);

    cout << "[";
    cout << myQueue.peek() << ", ";
    cout << myQueue.pop() << ", ";
    if (myQueue.empty())
        cout << "true";
    else
        cout << "false";

    cout << "]";

    return 0;
}