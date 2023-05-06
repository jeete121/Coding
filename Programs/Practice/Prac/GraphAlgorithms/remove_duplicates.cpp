#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{

    set<char> st;
    int l = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.find(s[i]) == st.end())
        {
            s[l++] = s[i];
        }
        st.insert(s[i]);
    }
    s.resize(l);
    return s;
}
int main()
{
    string s = "iloveprogramming";

    cout << removeDuplicates(s) << "\n";

    return 0;
}