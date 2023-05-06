#include <bits/stdc++.h>
using namespace std;

int sockMerchant(int n, vector<int> ar)
{
    int i, sum = 0;
    int c[101], m[101];

    for (i = 0; i <= 100; i++)
    {
        c[i] = 0;
        m[i] = 0;
    }
    for (i = 0; i < n; i++)
        c[ar[i]]++;
    for (i = 0; i <= 100; i++)
    {
        if (c[i] >= 2)
        {
            m[i] = c[i] / 2;
        }
    }
    for (i = 0; i <= 100; i++)
    {
        sum = sum + m[i];
    }
    return sum;
}

int main()
{
    int n = 7;
    vector<int> ar = {1, 2, 1, 2, 1, 3, 2};
    cout << sockMerchant(n, ar);
    return 0;
}
