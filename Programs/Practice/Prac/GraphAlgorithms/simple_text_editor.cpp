#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    stack<string> st;
    string s = "";
    st.push(s);
    int p = 0;
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            string str;
            cin >> str;
            s.append(str);
            st.push(s);
        }
        else if (x == 2)
        {
            int k;
            cin >> k;
            s.erase(s.size() - k, k);

            st.push(s);
        }
        else if (x == 3)
        {
            int k;
            cin >> k;
            cout << s[k - 1] << "\n";
        }
        else if (x == 4)
        {
            st.pop();
            s = st.top();
        }
    }
    return 0;
}
