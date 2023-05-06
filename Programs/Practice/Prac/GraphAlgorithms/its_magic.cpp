#include <bits/stdc++.h>
using namespace std;

long long itsMagic(long long n, long long a[])
{
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        sum += a[i];
    }
    long long ans = INT_MAX, index = -1;
    for (long long i = 0; i < n; i++)
    {
        if ((sum - a[i]) % 7 == 0)
        {
            if (a[i] < ans)
            {
                ans = a[i];
                index = i;
            }
        }
    }
    return index;
}
int main()
{
    long long n = 5;

    long long a[n] = {14, 7, 8, 2, 4};

    cout << itsMagic(n, a) << "\n";

    return 0;
}