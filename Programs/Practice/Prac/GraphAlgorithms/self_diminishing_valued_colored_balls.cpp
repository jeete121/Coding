#include <bits/stdc++.h>
using namespace std;

bool check(int val, vector<int> &inventory, int orders)
{
    int res = 0;
    for (int &num : inventory)
    {
        res += max(num - val + 1, 0);
        if (res > orders)
            return true;
    }
    return res > orders;
}

int maxProfit(vector<int> &inventory, int orders)
{

    int left = 1, right = 1e9;
    int magic = 1e9 + 7;

    while (right > left)
    {
        int mid = left + (right - left) / 2;
        if (check(mid, inventory, orders))
            left = mid + 1;
        else
            right = mid;
    }

    int curr = 0;
    long long p = 0;

    for (int &num : inventory)
    {
        if (num < right)
            continue;
        p += (long long)(right + num) * (num - right + 1) / 2;
        curr += (num - right + 1);
    }

    p += (long long)(orders - curr) * (right - 1);

    return (int)(p % magic);
}

int main()
{
    vector<int> inventory = {2, 5};
    int orders = 4;

    cout << maxProfit(inventory, orders);

    return 0;
}