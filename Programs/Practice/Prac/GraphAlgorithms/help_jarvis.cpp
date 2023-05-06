#include <bits/stdc++.h>
using namespace std;

bool helpJarvis(string s)
{
    vector<char> v;
    for (int i = 0; i < s.size(); i++)
        v.push_back(s[i]);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++)
        if ((v[i + 1] - v[i]) != 1)
            return false;

    return true;
}
int main()
{

    string s = "4231";

    bool ans = helpJarvis(s);
    if (ans == true)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}