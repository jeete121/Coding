#include <bits/stdc++.h>
using namespace std;

bool isPrefixString(string s, vector<string> &words)
{

    int k = 0;
    string str = "";
    for (int i = 0; i < words.size() && k < s.size(); i++)
    {
        str += words[i];

        if (str.size() > s.size())
            return false;
        else
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                if (s[k] == words[i][j])
                {
                    k++;
                }
                else
                    return false;
            }
        }
    }
    if (k == s.size())
        return true;
    return false;
}
int main()
{
    string s = "iloveleetcode";
    vector<string> words = {"i", "love", "leetcode", "apples"};

    if (isPrefixString(s, words))
        cout << "true\n";

    else
        cout << "false\n";

    return 0;
}