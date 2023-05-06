#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int n = s.size();
    if (n == 0)
        return "";
    int i = 0, j = n - 1;
    while (i < n && s[i] == ' ')
        i++;
    while (j > 0 && s[j] == ' ')
        j--;
    stack<string> st;
    while (i <= j)
    {
        string x = "";
        while (i <= j && s[i] != ' ')
        {
            x += s[i];
            i++;
        }
        st.push(x);
        while (i <= j && s[i] == ' ')
            i++;
    }
    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
        if (!st.empty())
            res += " ";
    }
    return res;
}
int main()
{
    string s = "the sky is blue";
    cout << reverseWords(s);
    return 0;
}