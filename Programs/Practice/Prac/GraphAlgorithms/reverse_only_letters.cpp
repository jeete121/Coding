#include <bits/stdc++.h>
using namespace std;

string reverseOnlyLetters(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            st.push(s[i]);
        else if (s[i] >= 'a' && s[i] <= 'z')
            st.push(s[i]);
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = st.top();
            st.pop();
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = st.top();
            st.pop();
        }
    }
    return s;
}

int main()
{
    string str = "a-bC-dEf-ghIj";
    cout << reverseOnlyLetters(str);
    return 0;
}