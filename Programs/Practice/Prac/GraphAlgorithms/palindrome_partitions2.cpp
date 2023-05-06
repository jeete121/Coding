#include <bits/stdc++.h>
using namespace std;

int minCut(const string &s)
{
    //find length of string
    int len = s.size();
    vector<int> pal(len, 0);
    vector<int> cuts(len + 1, len);
    cuts[0] = -1;
    for (int i = 0; i < len; ++i)
    {
        cuts[i + 1] = min(cuts[i] + 1, cuts[i + 1]);
        for (int j = 0; j < i; ++j)
            if (s[i] == s[j] && (i - j < 3 || pal[j + 1] == i - j - 2))
            {
                pal[j] = i - j;
                cuts[i + 1] = min(cuts[j] + 1, cuts[i + 1]);
            }
    }
    return cuts[len];
}

int main()
{
    string s = "aab";

    cout << minCut(s);

    return 0;
}