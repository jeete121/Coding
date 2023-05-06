#include <bits/stdc++.h>
using namespace std;

string trickyAddition(int n, int m)
{

    vector<long long> a, b;
    while (n)
    {
        a.push_back(n % 10);
        n = n / 10;
    }
    while (m)
    {
        b.push_back(m % 10);
        m = m / 10;
    }
    long long carry = 0;
    n = a.size();
    m = b.size();
    string ans = "";

    long long i = n - 1, j = m - 1;
    while (i >= 0 || j >= 0)
    {
        if (i >= 0 && j >= 0)
        {
            long long x = a[i] + b[j] + carry;
            long long y = x;
            if (x >= 10)
            {
                carry = x % 10;
                x = x / 10;
            }
            else
                carry = 0;
            ans += to_string(x);
            if (i == 0 && j == 0 && y >= 10)
            {
                ans += to_string(y % 10);
                carry = 0;
            }
            i--;
            j--;
        }
        else if (i >= 0)
        {
            long long x = a[i] + carry;
            int y = x;
            if (x >= 10)
            {
                carry = x % 10;
                x = x / 10;
            }
            else
                carry = 0;
            ans += to_string(x);
            if (i == 0 && y >= 10)
            {
                ans += to_string(y % 10);
                carry = 0;
            }
            i--;
        }
        else if (j >= 0)
        {
            long long x = b[j] + carry;
            int y = x;
            if (x >= 10)
            {
                carry = x % 10;
                x = x / 10;
            }
            else
                carry = 0;
            ans += to_string(x);
            if (j == 0 && y >= 10)
            {
                ans += to_string(y % 10);
                carry = 0;
            }
            j--;
        }
    }
    if (carry > 0)
        ans += to_string(carry);
    return ans;
}
int main()
{

    long long n = 26, m = 9;

    cout << trickyAddition(n, m) << "\n";

    return 0;
}