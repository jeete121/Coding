#include <bits/stdc++.h>
using namespace std;

void stringGame(string s)
{
    int n = s.size();
    set<char> st;
    for (int i = 0; i < n; i++)
        st.insert(s[i]);
    int len = st.size();
    if (len & 1)
        cout << "Player1\n";
    else
        cout << "Player2\n";
}
int main()
{

    string s = "aba";

    stringGame(s);

    return 0;
}