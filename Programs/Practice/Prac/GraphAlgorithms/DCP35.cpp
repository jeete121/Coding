#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<char> &data)
{
    int n = data.size();
    int p = 0, i = 0;

    int q = n - 1;
    char t;
    while (i < n)
    {
        if (data[i] == 'R')
        {
            t = data[i];
            data[i] = data[p];
            data[p] = t;
            ++p;
            ++i;
        }

        else if (data[i] == 'G')
        {
            t = data[i];
            data[i] = data[q];
            data[q] = t;
            --q;
        }
        else
        {
            ++i;
        }
    }
}

int main()
{
    vector<char> data = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};

    threeWayPartition(data);

    cout << "[";
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i];
        if (i != data.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}