#include <bits/stdc++.h>
using namespace std;

long long bit(long long n)
{
    long long cnt = 0;
    while (n)
    {
        cnt++;
        n = n & (n - 1);
    }
    return cnt;
}

long long understandComputer(long long n)
{

    long long ans = 0;
    long long i = 1;
    while (i <= sqrt(n))
    {
        i = i * 2;
        if (n / i >= i / 2)
            ans = n - n / i;
        else
            ans = n - i / 2 + 1;
    }
    return ans;
}
int main()
{

    long long n = 3;

    cout << understandComputer(n) << "\n";

    return 0;
}