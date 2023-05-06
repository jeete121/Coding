#include <bits/stdc++.h>
using namespace std;

string decode(string s)
{
    int i = 0;
    string res;
    res.resize(s.size());
    int n, m, x, flag = 0;
    while (i < s.size())
    {
        x = s.size() - i;
        if (x & 1)
        {
            if (flag == 0)
            {
                res[res.size() / 2] = s[i];
                flag = 1;
                n = res.size() / 2 - 1;
                m = res.size() / 2 + 1;
            }
            else
            {
                res[m] = s[i];
                m++;
            }
        }
        else
        {
            if (flag == 0)
            {
                res[res.size() / 2 - 1] = s[i];
                flag = 1;
                n = res.size() / 2 - 2;
                m = res.size() / 2;
            }
            else
            {
                res[n] = s[i];
                n--;
            }
        }
        i++;
    }
    return res;
}
int main()
{

    string s = "wrien";

    cout << decode(s) << "\n";

    return 0;
}