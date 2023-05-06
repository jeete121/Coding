#include <bits/stdc++.h>
using namespace std;

long long res;
long long numOfDivisors(long long n, long long k)
{

    res = res - k * (n * (n + 1) / 2) + n * (n + 1) / 2;
    n = n / k;
    if (n == 0)
        return res;
    return numOfDivisors(n, k);
}
int main()
{

    long long n = 10, k = 3;
    res = (n * (n + 1)) / 2;
    n = n / k;
    cout << numOfDivisors(n, k) << "\n";
    return 0;
}