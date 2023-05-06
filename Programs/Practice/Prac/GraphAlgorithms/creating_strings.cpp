#include <bits/stdc++.h>
using namespace std;

void creatingStrings(string s)
{

    sort(s.begin(), s.end());
    set<string> st;
    do
    {
        st.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << st.size() << "\n";
    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it << "\n";
}
int main()
{
    string s = "aabac";

    creatingStrings(s);

    return 0;
}