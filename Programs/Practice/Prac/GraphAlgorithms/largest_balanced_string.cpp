#include <bits/stdc++.h>
using namespace std;

int largestBalancedString(string s)
{

    int o1 = 0, c1 = 0, o2 = 0, c2 = 0, o3 = 0, c3 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            o1++;
        else if (s[i] == ')')
            c1++;
        else if (s[i] == '{')
            o2++;
        else if (s[i] == '}')
            c2++;
        else if (s[i] == '[')
            o3++;
        else
            c3++;
    }
    int res = min(c1, o1) * 2 + min(c2, o2) * 2 + min(c3, o3) * 2;
    return res;
}
int main()
{

    string s = "))[]]((";

    cout << largestBalancedString(s) << "\n";

    return 0;
}
