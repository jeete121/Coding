#include <bits/stdc++.h>
using namespace std;

string cyclicShifts(int a)
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
    int len = res.size();
    while (len != 16)
    {
        res += '0';
        len++;
    }
    reverse(res.begin(), res.end());
    return res;
}
int cyclicShifts1(string s)
{
    int res = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            res += pow(2, n - i - 1);
    }
    return res;
}
int main()
{

    int n = 7881, m = 5;
    char c = 'L';
    string res = cyclicShifts(n);

    int len = res.size(), result;
    m = m % len;
    if (c == 'L')
    {
        string s1 = "", str = "";
        for (int i = 0; i < m; i++)
            str += res[i];
        for (int i = m; i < len; i++)
            s1 += res[i];
        for (int i = 0; i < m; i++)
            s1 += str[i];
        result = cyclicShifts1(s1);
        cout << result << "\n";
    }
    else
    {
        string s1 = "", str = "";
        int cnt = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            str += res[i];
            cnt++;
            if (cnt == m)
                break;
        }
        string ans = "";
        for (int i = m - 1; i >= 0; i--)
            ans += str[i];
        for (int i = 0; i < len - m; i++)
            ans += res[i];
        result = cyclicShifts1(ans);
        cout << result << "\n";
    }

    return 0;
}