#include <bits/stdc++.h>
using namespace std;

void carNames(string s)
{

    int n = s.size();
    set<char> st;
    for (int i = 0; i < n; i++)
        st.insert(s[i]);
    int len = st.size();
    if (len == 3)
    {
        int i = 0;
        int cnt1 = 1, cnt2 = 1, cnt3 = 1;
        while (i < n - 1 && s[i] == s[i + 1])
        {
            cnt1++;
            i++;
        }
        i++;
        while (i < n - 1 && s[i] == s[i + 1])
        {
            cnt2++;
            i++;
        }
        i++;
        while (i < n - 1 && s[i] == s[i + 1])
        {
            cnt3++;
            i++;
        }
        if ((cnt1 == cnt2) && (cnt2 == cnt3) &&
            (cnt1 + cnt2 + cnt3) == n)
            cout << "OK\n";
        else
            cout << "Not OK\n";
    }
    else
        cout << "Not OK\n";
}
int main()
{

    string s = "bbbrrriii";

    carNames(s);

    return 0;
}