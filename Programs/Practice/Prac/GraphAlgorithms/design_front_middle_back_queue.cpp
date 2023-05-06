#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue
{
    deque<int> dq;

public:
    FrontMiddleBackQueue()
    {
        dq.clear();
    }

    void pushFront(int val)
    {
        dq.push_front(val);
    }

    void pushMiddle(int val)
    {
        int n = dq.size();
        dq.insert(dq.begin() + n / 2, val);
    }

    void pushBack(int val)
    {
        dq.push_back(val);
    }

    int popFront()
    {
        if (dq.empty())
            return -1;

        int ans = dq.front();
        dq.pop_front();
        return ans;
    }

    int popMiddle()
    {
        if (dq.empty())
            return -1;

        int mid = (dq.size() - 1) / 2;
        int ans = *(dq.begin() + mid);
        dq.erase(dq.begin() + mid);
        return ans;
    }

    int popBack()
    {
        if (dq.empty())
            return -1;

        int ans = dq.back();
        dq.pop_back();
        return ans;
    }
};

int main()
{
    FrontMiddleBackQueue q;
    q.pushFront(1);
    q.pushBack(2);
    q.pushMiddle(3);
    q.pushMiddle(4);
    cout << "[";
    cout << q.popFront() << ", ";
    cout << q.popMiddle() << ", ";
    cout << q.popMiddle() << ", ";
    cout << q.popBack() << ", ";
    cout << q.popFront();
    cout << "]";

    return 0;
}