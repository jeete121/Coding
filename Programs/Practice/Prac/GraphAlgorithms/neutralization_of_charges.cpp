#include <bits/stdc++.h>
using namespace std;

void chargeNeutralization(int n, string s)
{
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (st.size() >= 2)
        {
            char x = st.top();
            st.pop();
            char y = st.top();
            st.pop();
            if (x != y)
            {
                st.push(y);
                st.push(x);
            }
        }
        st.push(s[i]);
    }
    if (st.size() >= 2)
    {
        char x = st.top();
        st.pop();
        char y = st.top();
        st.pop();
        if (x != y)
        {
            st.push(y);
            st.push(x);
        }
    }
    cout << st.size() << "\n";
    string str = "";
    while (!st.empty())
    {
        str += st.top();
        st.pop();
    }
    reverse(str.begin(), str.end());
    cout << str << "\n";
}
int main()
{
    int n = 12;
    string s = "aaacccbbcccd";

    chargeNeutralization(n, s);

    return 0;
}