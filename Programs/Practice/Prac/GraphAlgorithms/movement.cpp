#include <bits/stdc++.h>
using namespace std;

long long movement(long long n)
{
    long long cnt = 0;
    while (n >= 5)
    {
        cnt++;
        n = n - 5;
    }
    while (n >= 4)
    {
        cnt++;
        n = n - 4;
    }
    while (n >= 3)
    {
        cnt++;
        n = n - 3;
    }
    while (n >= 2)
    {
        cnt++;
        n = n - 2;
    }
    if (n == 1)
        cnt++;
    return cnt;
}
int main()
{
    long long n = 26;

    cout << movement(n) << "\n";

    return 0;
}