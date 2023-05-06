#include <bits/stdc++.h>
using namespace std;

bool hasAllCodes(string s, int k)
{
    unordered_set<string> st;
    if (k > s.size())
        return false;
    for (int i = 0; i <= s.length() - k; i++)
    {
        st.insert(s.substr(i, k));
    }
    if (st.size() == pow(2, k))
        return true;
    return false;
}

int main()
{
    string s = "00110110";
    int k = 2;

    if (hasAllCodes(s, k))
        cout << "true";
    else
        cout << "false";

    return 0;
}