#include <bits/stdc++.h>
using namespace std;

int lonelyinteger(vector<int> a)
{
    int res = a[0];
    for (int i = 1; i < a.size(); i++)
        res = res ^ a[i];
    return res;
}

int main()
{
    vector<int> a = {0, 0, 1, 2, 1};

    cout << lonelyinteger(a);

    return 0;
}
