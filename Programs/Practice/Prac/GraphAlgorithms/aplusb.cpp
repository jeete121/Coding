#include <bits/stdc++.h>
using namespace std;

string aPlusb(string num1, string num2)
{
    int n = num1.size(), m = num2.size();
    if (n == 0)
        return num2;
    if (m == 0)
        return num1;
    string res = "";
    int carry = 0;
    if (n == m)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            int x = carry + num1[i] - '0' + num2[i] - '0';
            int y = x;
            x = x % 10;
            ostringstream str1;
            str1 << x;
            string strin = str1.str();
            res += strin;
            carry = (y) / 10;
        }
        if (carry > 0)
        {
            int x = carry;
            ostringstream str1;
            str1 << x;
            string strin = str1.str();
            res += strin;
        }
    }
    else if (n > m)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            int x = carry + num1[n - m + i] - '0' + num2[i] - '0';
            int y = x;
            // cout<<y<<endl;
            x = x % 10;
            ostringstream str1;
            str1 << x;
            string strin = str1.str();
            res += strin;
            carry = (y) / 10;
            // cout<<carry<<"\n";
        }
        for (int i = n - m - 1; i >= 0; i--)
        {
            int x = carry + num1[i] - '0';
            int y = x;
            x = x % 10;
            ostringstream str1;
            str1 << x;
            string strin = str1.str();
            res += strin;
            carry = (y) / 10;
        }
        if (carry > 0)
        {
            int x = carry;
            ostringstream str1;
            str1 << x;
            string strin = str1.str();
            res += strin;
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            int x = carry + num1[i] - '0' + num2[m - n + i] - '0';
            int y = x;
            x = x % 10;
            ostringstream str1;
            str1 << x;
            string strin = str1.str();
            res += strin;
            carry = (y) / 10;
        }
        for (int i = m - n - 1; i >= 0; i--)
        {
            int x = carry + num2[i] - '0';
            int y = x;
            x = x % 10;
            ostringstream str1;
            str1 << x;
            string strin = str1.str();
            res += strin;
            carry = (y) / 10;
        }
        if (carry > 0)
        {
            int x = carry;
            ostringstream str1;
            str1 << x;
            string strin = str1.str();
            res += strin;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    string a = "10", b = "14";

    string ans = aPlusb(a, b);
    cout << ans << "\n";
    return 0;
}