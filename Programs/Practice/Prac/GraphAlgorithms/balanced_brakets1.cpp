#include <bits/stdc++.h>
using namespace std;

bool balancedBracket(string s)
{
    int n = s.size();
    stack<char> st;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.empty())
            {
                flag = 1;
                break;
            }
            else
            {
                if (s[i] == ')' && st.top() != '(')
                {
                    flag = 1;
                    break;
                }
                else if (s[i] == '}' && st.top() != '{')
                {
                    flag = 1;
                    break;
                }
                else if (s[i] == '[' && st.top() != ']')
                {
                    flag = 1;
                    break;
                }
                else
                    st.pop();
            }
        }
    }
    if (flag == 1)
        return false;
    else
    {
        if (st.empty())
            return true;
        else
            return false;
    }
}
int main()
{

    string s = "{[()]}";

    if (balancedBracket(s))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}