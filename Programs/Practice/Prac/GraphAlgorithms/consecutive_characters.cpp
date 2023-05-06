#include <bits/stdc++.h>
using namespace std;


int maxPower(string s)
{
    int n = s.size();
    int i = 0;
    int max1 = 0;
    while (i < n)
    {
        int cnt = 1;
        while (i < n - 1 && s[i] == s[i + 1])
        {
            cnt++;
            i++;
        }
        i++;
        max1 = max(cnt, max1);
    }
    return max1;
}

int main()
{
    string str = "abbcccddddeeeeedcba";
    cout << maxPower(str);
    return 0;
}