#include <bits/stdc++.h>
using namespace std;

int interestingString(string s)
{
    set<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 1; j <= s.size() - i; j++)
            st.insert(s.substr(i, j));
    }
    return st.size();
}
int main()
{

    string s = "abcd";

    cout << interestingString(s) << "\n";

    return 0;
}