#include <bits/stdc++.h>
using namespace std;

int isPrefixOfWord(string s, string t)
{
    vector<string> v;
    int n = s.size();
    int i = 0;
    while (i < n)
    {
        string str = "";
        while (i < n && s[i] == ' ')
            i++;
        while (i < n && s[i] != ' ')
        {
            str += s[i];
            i++;
        }
        i++;
        v.push_back(str);
    }
    int index = -1;
    for (int i = 0; i < v.size(); i++)
    {
        string str = v[i];
        int flag = 0;
        int len = str.size();
        if (len >= t.size())
        {
            for (int j = 0; j < t.size(); j++)
            {
                if (t[j] != str[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                index = i + 1;
                break;
            }
        }
    }
    return index;
}

int main()
{
    string sentence = "i love eating burger";
    string searchWord = "burg";
    cout << isPrefixOfWord(sentence, searchWord);
    return 0;
}