#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s)
{
    stack<int> v;
    int flag = 0, flag1 = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            v.push(i), flag++, flag1 = 0;
        else if (s[i] == ')')
        {
            if (v.empty() || flag1 || !flag)
                v.push(i), flag1 = 1;
            else
            {
                v.pop();
                flag--;
            }
        }
    }
    string ans = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (!v.empty() && i == v.top())
            v.pop();
        else
            ans += s[i];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "a)b(c)d";

    cout << minRemoveToMakeValid(s);

    return 0;
}