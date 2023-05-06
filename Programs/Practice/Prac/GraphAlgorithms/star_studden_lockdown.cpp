#include <bits/stdc++.h>
using namespace std;

long long starStuddedLockdown(int n, string s)
{
    long long arr[n] = {0};
    map<char, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        if (mp.find(s[i]) == mp.end())
            arr[i] = 0;
        else
            arr[i] = mp[s[i]];
        mp[s[i]]++;
    }
    long long sum = 0;
    for (long long i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
int main()
{

    long long n = 5;
    string s = "abaab";

    cout << starStuddedLockdown(n, s);

    return 0;
}