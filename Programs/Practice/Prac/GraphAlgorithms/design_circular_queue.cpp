#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
public:
    vector<int> v;
    int head;
    int tail;
    int size;

    MyCircularQueue(int k)
    {

        v.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    queue<int> q;

    bool enQueue(int value)
    {

        if (isFull())
            return false;
        if (isEmpty())
            head = 0;
        tail = (tail + 1) % size;
        v[tail] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        if (head == tail)
        {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }

    int Front()
    {

        if (isEmpty())
            return -1;
        return v[head];
    }

    int Rear()
    {

        if (isEmpty())
            return -1;
        return v[tail];
    }

    bool isEmpty()
    {

        if (head == -1)
            return true;
        return false;
    }

    bool isFull()
    {

        return ((tail + 1) % size) == head;
    }
};

int main()
{
    MyCircularQueue myCircularQueue(3);

    cout << "[";
    if (myCircularQueue.enQueue(1))
        cout << "true, ";
    else
        cout << "false, ";
    if (myCircularQueue.enQueue(2))
        cout << "true, ";
    else
        cout << "false, ";
    if (myCircularQueue.enQueue(3))
        cout << "true, ";
    else
        cout << "false, ";
    if (myCircularQueue.enQueue(4))
        cout << "true, ";
    else
        cout << "false, ";
    cout << myCircularQueue.Rear() << ", ";
    if (myCircularQueue.isFull())
        cout << "true, ";
    else
        cout << "false, ";
    if (myCircularQueue.deQueue())
        cout << "true, ";
    else
        cout << "false, ";
    if (myCircularQueue.enQueue(4))
        cout << "true, ";
    else
        cout << "false, ";
    cout << myCircularQueue.Rear();

    cout << "]";

    return 0;
}