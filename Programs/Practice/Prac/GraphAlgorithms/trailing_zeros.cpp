#include <bits/stdc++.h>
using namespace std;

long long trailingZeros(long long n)
{
    long long cnt = 0;
    while (n)
    {
        cnt += n / 5;
        n = n / 5;
    }
    return cnt;
}
int main()
{
    long long n = 20;

    cout<<trailingZeros(n);
    
    return 0;
}