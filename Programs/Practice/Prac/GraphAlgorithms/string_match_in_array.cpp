#include <bits/stdc++.h>
using namespace std;


vector<string> stringMatching(vector<string> &words)
{
    vector<string> res;
    unordered_set<string> st;
    int n = words.size();
    for (int i = 0; i < n; i++)
    {
        string str = words[i];
        for (int j = 0; j < n; j++)
        {
            string s = words[j];
            if (i != j)
            {
                if (s.size() >= str.size())
                {
                    for (int k = 0; k <= s.size() - str.size(); k++)
                    {
                        int flag = 0;
                        for (int l = 0; l < str.size(); l++)
                        {
                            if (str[l] != s[l + k])
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 0)
                        {
                            st.insert(str);
                            break;
                        }
                    }
                }
            }
        }
    }
    for (auto it = st.begin(); it != st.end(); it++)
        res.push_back(*it);
    return res;
}
int main()
{
    vector<string> words = {"mass", "as", "hero", "superhero"};
    vector<string> match = stringMatching(words);
    for (int i = 0; i < match.size(); i++)
        cout << match[i] << " ";
    return 0;
}