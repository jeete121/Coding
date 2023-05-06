#include <bits/stdc++.h>
using namespace std;

string firstOccurrences(string s)
{

    int i = 0;
    int l = 0;
    set<char> st;
    while (i < s.size())
    {
        if (st.find(s[i]) == st.end())
        {
            s[l++] = s[i];
            st.insert(s[i]);
        }
        i++;
    }
    s.resize(l);
    return s;
}
int main()
{

    string s = "aasdvasvavda";

    cout << firstOccurrences(s) << "\n";

    return 0;
}