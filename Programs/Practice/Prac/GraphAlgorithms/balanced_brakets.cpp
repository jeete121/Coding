#include <bits/stdc++.h>
using namespace std;

string isBalanced(string s)
{
    stack<char> st;
    if (s.size() & 1)
        return "NO";
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (st.empty())
                    return "NO";
                if ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{'))
                    st.pop();
                else
                    return "NO";
            }
        }
    }
    if (!st.empty())
        return "NO";
    return "YES";
}

int main()
{
    int n = 3;
    string str[3] = {"{[()]}", "{[(])}", "{{[[(())]]}}"};
    for (int i = 0; i < n; i++)
    {
        cout << isBalanced(str[i]) << "\n";
    }
    return 0;
}
