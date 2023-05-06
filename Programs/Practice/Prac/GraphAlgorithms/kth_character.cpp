#include <bits/stdc++.h>
using namespace std;

string kthCharacter(string s)
{

    int n = s.size();
    set<char> st;
    for (int i = 0; i < n; i++)
        st.insert(s[i]);
    string ans = "";
    for (auto it = st.begin(); it != st.end(); it++)
    {
        string str = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] != *it)
                str += s[i];
        }
        if (ans == "")
            ans = str;
        else
            ans = min(ans, str);
    }
    return ans;
}
int main()
{
    string s = "appleap";

    cout << kthCharacter(s) << "\n";

    return 0;
}