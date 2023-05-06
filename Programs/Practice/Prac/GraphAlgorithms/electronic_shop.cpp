#include <bits/stdc++.h>
using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b)
{
    int n = keyboards.size(), m = drives.size();
    sort(keyboards.begin(), keyboards.end(), greater<int>());
    sort(drives.begin(), drives.end());
    int res = -1;
    for (int i = 0, j = 0; i < n; i++)
    {
        for (; j < m; j++)
        {
            if (keyboards[i] + drives[j] > b)
                break;
            if (keyboards[i] + drives[j] > res)
                res = keyboards[i] + drives[j];
        }
    }
    return res;
}
int main()
{
    int b = 10, n = 2, m = 3;
    vector<int> keyboards = {3, 1};
    vector<int> drives = {5, 2, 8};

    cout << getMoneySpent(keyboards, drives, b);
    return 0;
}
