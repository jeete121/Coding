#include <bits/stdc++.h>
using namespace std;

long long count(string s)
{
    set<char> st;
    long long res = 1;
    int x = st.size();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            st.insert(s[i]);
        else if (s[i] == '_')
        {

            res *= st.size();
            x = st.size();
        }
    }

    return res;
}
int main()
{
    string s = "ab_ae_";

    cout << count(s) << "\n";

    return 0;
}