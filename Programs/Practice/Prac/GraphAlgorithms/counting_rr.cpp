#include <bits/stdc++.h>
using namespace std;

int counttingrr(string s)
{
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'r' && s[i + 1] == 'r')
            cnt++;
    }
    return cnt;
}
int main()
{
    string s = "rrrabc";

    cout << counttingrr(s) << "\n";

    return 0;
}