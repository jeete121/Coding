#include <bits/stdc++.h>
using namespace std;

double averageWaitingTime(vector<vector<int>> &customers)
{
    double totalTime = customers[0][1];
    int currTime = customers[0][1] + customers[0][0];

    for (int i = 1; i < customers.size(); i++)
    {
        int arrivalTime = customers[i][0];
        int waitTime = customers[i][1];

        if (arrivalTime < currTime)
        {
            totalTime += (currTime - arrivalTime + waitTime);
            currTime += waitTime;
        }
        else
        {
            totalTime += waitTime;
            currTime = arrivalTime + waitTime;
        }
    }

    return totalTime / customers.size();
}

int main()
{
    vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};

    cout << averageWaitingTime(customers);

    return 0;
}