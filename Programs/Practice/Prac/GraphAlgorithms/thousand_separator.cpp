#include <bits/stdc++.h>
using namespace std;

string thousandSeparator(int n)
{
    string s = to_string(n);
    int len = s.size();
    int i = len - 1;
    string str = "";
    while (true)
    {
        int cnt = 0;
        while (i >= 0)
        {
            str = s[i] + str;
            cnt++;
            i--;
            if (cnt == 3)
                break;
        }
        if (i >= 0)
            str = '.' + str;
        if (i < 0)
            break;
    }
    return str;
}

int main()
{
    int n = 1234;
    cout << thousandSeparator(n);
    return 0;
}