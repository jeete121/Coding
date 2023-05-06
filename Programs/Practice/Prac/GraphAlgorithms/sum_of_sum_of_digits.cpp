#include <bits/stdc++.h>
using namespace std;
long long singleDigit(long long n)
{
    long long res = 0;
    while (n >= 10)
    {
        res = 0;
        while (n)
        {
            res += n % 10;
            n = n / 10;
        }
        n = res;
    }
    return n;
}
int main()
{

    long long n = 5;

    long long arr[n] = {13, 345, 193, 44444, 100303};

    for (long long i = 0; i < n; i++)
        arr[i] = singleDigit(arr[i]);
    sort(arr, arr + n);
    long long sum1[n], sum2[n];
    sum1[n - 1] = arr[n - 1];
    for (long long i = n - 2; i >= 0; i--)
        sum1[i] = sum1[i + 1] + arr[i];
    sum2[0] = arr[0];
    for (long long i = 1; i < n; i++)
        sum2[i] = arr[i] + sum2[i - 1];

    long long x = 1, y = 4;

    if (x == 1)
        cout << sum1[n - y] << "\n";
    else
        cout << sum2[y - 1] << "\n";
}