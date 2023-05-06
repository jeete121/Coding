#include <bits/stdc++.h>
using namespace std;

set<long long> st;
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void fun(long long n)
{
    if (n > 1000000000)
        return;
    if (n != 0)
        st.insert(n);
    fun(n * 10 + 4);
    fun(n * 10 + 7);
}

int specialNumber(int n)
{
    long long num = 0;
    fun(num);
    long long ans = 0;
    for (auto i : st)
    {
        for (auto j : st)
        {
            if (i <= n && j <= n && j >= i)
            {
                if (gcd(i, j) == 1)
                    ans++;
            }
        }
    }
    return ans;
}
int main()
{

    long long n = 10;

    cout << specialNumber(n);

    return 0;
}