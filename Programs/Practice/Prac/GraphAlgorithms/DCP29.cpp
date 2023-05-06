#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str = "AAAABBBCCDAA";
    char t = str[0];

    int i = 0;
    int cnt = 1;
    int n = str.size();
    string res = "";
    while (i < n)
    {
        cnt = 1;
        i++;
        while (i < n && str[i] == str[i - 1])
        {
            i++;
            cnt++;
        }
        res += to_string(cnt);
        res += str[i-1];
    }
    cout << res << "\n";
    return 0;
}
