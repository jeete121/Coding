#include <bits/stdc++.h>
using namespace std;

int theDice(string s)
{
    int n = s.size();
    int i = 0, cnt = 0;
    while (i < n)
    {
        while (i < n && s[i] == '6')
            i++;
        cnt++;
        i++;
    }
    if (s[n - 1] == '6')
        return -1;
    else
        return cnt;
}
int main()
{
    string s = "3662123";

    cout << theDice(s) << "\n";

    return 0;
}