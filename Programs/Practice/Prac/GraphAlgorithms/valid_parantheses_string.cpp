#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s)
{
    int n = s.size();
    if (n == 0)
        return true;
    stack<pair<char, int>> st1, st2;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st1.push({s[i], i});
        else if (s[i] == '*')
            st2.push({s[i], i});
        else
        {
            if (!st1.empty())
                st1.pop();
            else if (!st2.empty())
                st2.pop();
            else
                return false;
        }
    }
    while (!st1.empty() && !st2.empty())
    {
        if (st1.top().second > st2.top().second)
            return false;
        else
        {
            {
                st1.pop();
                st2.pop();
            }
        }
    }
    if (st1.size())
        return false;
    return true;
}

int main()
{
    string str = "(()*";
    if (checkValidString(str))
        cout << "true";
    else
        cout << "false";
    return 0;
}