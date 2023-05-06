#include <bits/stdc++.h>
using namespace std;

int exumaiBlast(string s)
{

    vector<string> v;
    int i = 0;
    int n = s.size();
    while (i < n)
    {
        string str = "";
        while (i < n && s[i] != ' ')
        {
            str += s[i];
            i++;
        }
        v.push_back(str);
        i++;
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        string p = v[i];
        set<char> st;
        for (int i = 0; i < p.size(); i++)
            st.insert(p[i]);
        if (st.size() != p.size())
            cnt++;
    }
    return cnt;
}
int main()
{
    string s = "MY DREAM COMPANY IS GOOGLE";

    cout << exumaiBlast(s) << "\n";

    return 0;
}