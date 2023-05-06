#include <bits/stdc++.h>
using namespace std;

int numSpecialEquivGroups(vector<string> &A)
{
    unordered_set<string> set;
    for (auto &str : A)
    {
        string upper = "", lower = "";
        for (int i = 0; i < str.size(); ++i)
        {
            if (i & 1)
            {
                lower += str[i];
            }
            else
            {
                upper += str[i];
            }
        }
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        str = lower + upper;
        if (set.find(str) == set.end())
        {
            set.insert(str);
        }
    }
    return set.size();
}
int main()
{
    vector<string> A = {"abcd", "cdab", "cbad",
                        "xyzz", "zzxy", "zzyx"};

    cout << numSpecialEquivGroups(A);

    return 0;
}