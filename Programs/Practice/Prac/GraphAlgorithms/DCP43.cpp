#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int min1 = INT_MAX;

void push(int x)
{
    if (x < min1)
        min1 = x;
    v.push_back(x);
}

int top()
{
    return v[v.size() - 1];
}

void pop()
{
    int x = top();
    v.pop_back();
    if (x == min1)
    {
        min1 = INT_MAX;
        for (int i : v)
        {
            if (i < min1)
                min1 = i;
        }
    }
}

int getMin()
{
    return min1;
}

int main()
{
    push(-20);
    push(0);
    push(-3);
    cout << getMin();

    return 0;
}