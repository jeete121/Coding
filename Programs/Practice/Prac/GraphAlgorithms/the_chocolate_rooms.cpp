#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        set<string> st;
        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            string s;
            for (int j = 0; j < p; j++)
            {
                cin >> s;
                st.insert(s);
            }
        }
        if (st.size() >= k)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}