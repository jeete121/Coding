#include <bits/stdc++.h>
using namespace std;

int repeatedString(string str, long long n)
{
    long long len = str.size();
    long long cnt = 0;
    for (int i = 0; i < min(len, n); i++)
    {
        if (str[i] == 'a')
        {
            cnt++;
        }
    }
    if (n < len)
        return cnt;
    else
    {
        long long x = n / len;
        cnt = x * cnt;
        long long rem = n % len;
        for (int i = 0; i < rem; i++)
            if (str[i] == 'a')
                cnt++;
        return cnt;
    }
}
int main()
{

    string str = "aba";
    long long n = 10;
    cout << repeatedString(str, n);
    return 0;
}
