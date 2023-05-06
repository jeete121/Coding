#include <bits/stdc++.h>
using namespace std;
int zeros(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0')
            cnt++;
    return cnt;
}

int ones(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
            cnt++;
    return cnt;
}
int maxScore(string s)
{
    string str1, str2;
    int n = s.size();
    int i = 0, max1 = INT_MIN, res;
    while (i < n - 1)
    {
        str1 = s.substr(0, i + 1);
        str2 = s.substr(i + 1, n);
        res = zeros(str1) + ones(str2);
        if (res > max1)
            max1 = res;
        i++;
    }
    return max1;
}

int main()
{
    string s = "011101";
    cout << maxScore(s);
    return 0;
}