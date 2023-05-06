#include <bits/stdc++.h>
using namespace std;

string mostCommonWord(string paragraph, vector<string> &banned)
{
    int n = paragraph.size();
    map<string, int> mp;
    int i = 0;
    set<string> st;
    for (int i = 0; i < banned.size(); i++)
    {
        st.insert(banned[i]);
    }
    while (i < n)
    {
        string str = "";
        while (i < n && !isalpha(paragraph[i]))
        {
            i++;
        }
        while (i < n && paragraph[i] != ' ' && isalpha(paragraph[i]))
        {
            if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
            {
                str += paragraph[i] + 32;
            }
            else
            {
                str = str + paragraph[i];
            }
            i++;
        }
        if (st.find(str) != st.end())
            continue;
        else
        {
            if (str.size() > 0)
                mp[str]++;
        }
    }
    int max1 = INT_MIN;
    string res = "";
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > max1)
        {
            max1 = it->second;
            res = it->first;
        }
    }
    return res;
}

int main()
{
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    cout << mostCommonWord(paragraph, banned);

    return 0;
}