#include <bits/stdc++.h>
using namespace std;

vector<int> circularBuffer;
int maxSize;
int currIdx;
void LogDataStructure(int n)
{
    maxSize = n;
    circularBuffer.resize(n);

    currIdx = 0;
}
void record(int orderId)
{
    circularBuffer[currIdx] = orderId;
    currIdx = (currIdx + 1) % maxSize;
}
int getLast(int i)
{
    return circularBuffer[(currIdx - i + maxSize) % maxSize];
}

int main()
{
    vector<int> orderIds = {3, 4, 1, 6, 5, 2};

    LogDataStructure(orderIds.size());
    for (int i = 0; i < orderIds.size(); i++)
    {
        record(orderIds[i]);
    }

    int index = 3;
    cout << getLast(index);

    return 0;
}