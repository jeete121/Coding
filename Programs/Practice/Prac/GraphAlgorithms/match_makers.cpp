#include <bits/stdc++.h>
using namespace std;

long long matchMakers(long long n,
                      long long girl[],
                      long long boys[])
{

    sort(girl, girl + n);
    sort(boys, boys + n, greater<long long>());

    long long cnt = 0;
    for (long long i = 0; i < n; i++)
    {
        if (boys[i] % girl[i] == 0 || girl[i] % boys[i] == 0)
            cnt++;
    }
    return cnt;
}
int main()
{
    long long n = 4;

    long long girl[n] = {1, 6, 9, 12};
    long long boys[n] = {4, 12, 3, 9};

    cout << matchMakers(n, girl, boys) << "\n";

    return 0;
}