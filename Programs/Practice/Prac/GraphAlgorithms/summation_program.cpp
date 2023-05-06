#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n = 5;
    long long sum = 0;
    long long i = n, j = 2, p = 1;
    while (true)
    {
        long long k = n / j;
        if (i == k)
            break;
        else
        {
            sum += (i - k) * p;
            j++;
            i = k;
            p++;
        }
    }
    while (i > 0)
    {
        sum += n / i;
        i--;
    }
    cout << sum << "\n";
    return 0;
}