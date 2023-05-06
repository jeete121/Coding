#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> dp;
vector<string> wordBreak(string s, vector<string> &wordDict, int i)
{

    if (s.empty())
        return {""};

    if (dp.find(s) != dp.end())
        return dp[s];

    vector<string> subpart, wholepart;
    for (string word : wordDict)
    {
        string igot = s.substr(0, word.length());

        if (igot != word)
        {
            continue;
        }
        else
        {
            subpart = wordBreak(s.substr(word.length()), wordDict, 0);
        }

        for (string ans : subpart)
        {
            string space = ans.length() == 0 ? "" : " ";
            wholepart.push_back(word + space + ans);
        }
    }

    return dp[s] = wholepart;
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    dp.clear();
    return wordBreak(s, wordDict, 0);
}

int main()
{
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> res = wordBreak(s, wordDict);

    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ",";
    }
    cout << res[res.size() - 1];
    cout << "]";

    return 0;
}