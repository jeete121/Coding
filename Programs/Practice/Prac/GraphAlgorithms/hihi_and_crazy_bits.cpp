#include <bits/stdc++.h>
using namespace std;
string binary(long long a)
{
    string res = "";
    while (a)
    {
        if (a & 1)
            res += '1';
        else
            res += '0';
        a = a / 2;
    }
    return res;
}
bool check(string a, string b)
{
    int n = a.size(), m = b.size();
    if (n != m)
        return true;
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                cnt++;
        if (cnt == 1)
            return true;
        return false;
    }
}
int main()
{

    long long n = 6;
    string b = binary(n);
    long long res = n + 1;
    for (long long i = n + 1;; i++)
    {
        string a = binary(i);
        bool f = check(a, b);
        if (f == 1)
        {
            res = i;
            break;
        }
    }
    cout << res << "\n";
}