#include <bits/stdc++.h>
using namespace std;

long long numberOfPairs(long long n, long long a[])
{
    sort(a, a + n);
    long long i = 0, j = 0;
    long long cnt = 0, res = 0;
    while (i < n - 1)
    {
        j = i;
        cnt = 1;
        while (i < n - 1 && (a[i] == a[i + 1]))
        {
            i++;
            cnt++;
        }
        res += cnt * (cnt - 1) / 2;
        i++;
    }
    return res;
}
int main()
{
    long long n = 5;

    long long a[n] = {1, 3, 1, 4, 3};

    cout << numberOfPairs(n, a) << "\n";

    return 0;
}