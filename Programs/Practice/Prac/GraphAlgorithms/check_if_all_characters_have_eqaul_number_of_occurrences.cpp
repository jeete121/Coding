#include <bits/stdc++.h>
using namespace std;

bool areOccurrencesEqual(string s)
{

    int freq[26] = {0};

    //coutt frequency of each characters in the
    //string
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }
    int cnt = INT_MAX;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            if (cnt == INT_MAX)
                cnt = freq[i];
            else
            {
                if (freq[i] != cnt)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    string s = "abacbc";

    if (areOccurrencesEqual(s))
        cout << "true\n";

    else
        cout << "false\n";

    return 0;
}