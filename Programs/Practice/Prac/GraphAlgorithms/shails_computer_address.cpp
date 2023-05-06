#include <bits/stdc++.h>
using namespace std;

void computerAddress(string s)
{
    int n = s.size();
    int i = 0;
    int flag = 0;
    int cnt = 0;
    while (i < n)
    {
        string str = "";
        while (i < n && s[i] != '.')
        {
            str += s[i];
            i++;
        }
        cnt++;
        if (cnt > 4)
        {
            flag = 1;
            break;
        }
        stringstream geek(str);
        int x = 0;
        geek >> x;
        if (x > 255)
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (i == n + 1 && flag == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    string s = "255.255.255.0";

    computerAddress(s);

    return 0;
}