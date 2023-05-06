#include <bits/stdc++.h>
using namespace std;

string printingPress(string s, string r)
{
    sort(r.begin(), r.end());
    int n = s.size();
    int j = 0;
    int m = r.size();
    for (int i = 0; i < n; i++)
    {
        if (j < m && s[i] > r[j])
        {
            s[i] = r[j];
            j++;
        }
    }
    return s;
}
int main()
{

    string s = "bbbb", r = "aaa";

    cout << printingPress(s, r) << "\n";

    return 0;
}