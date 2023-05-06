#include <bits/stdc++.h>
using namespace std;

string Confidential(string s)
{
    int mid;
    if (s.size() & 1)
        mid = s.size() / 2;
    else
        mid = s.size() / 2 - 1;
    if (mid == 0)
        return s.substr(mid);
    return s[mid] + Confidential(s.substr(0, mid)) + Confidential(s.substr(mid + 1));
}
int main()
{

    int n = 3;

    string s = "abc";

    string res = Confidential(s);
    cout << res << "\n";

    return 0;
}