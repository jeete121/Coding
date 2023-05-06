#include <bits/stdc++.h>
using namespace std;

void fredoSums(long long n, long long a[])
{
    sort(a, a + n);
    long long i = 0, j = n - 1;
    long long sum = 0, sum1 = 0;
    while (i < j)
    {
        sum += abs(a[i] - a[j]);
        i++;
        j--;
    }
    for (long long i = 0; i < n; i += 2)
        sum1 += abs(a[i] - a[i + 1]);
    if (sum < sum1)
        cout << sum << " " << sum1 << "\n";
    else
        cout << sum1 << " " << sum << "\n";
}
int main()
{

    long long n = 4;

    long long a[n] = {10, 20, -10, 0};

    fredoSums(n, a);

    return 0;
}