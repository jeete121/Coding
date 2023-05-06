#include <bits/stdc++.h>
using namespace std;

int compareAlien(string a, string b, map<int, int> &mp)
{
    int i = 0;
    while (i < a.length() && i < b.length())
    {
        if (mp[a[i] - 'a'] > mp[b[i] - 'a'])
            return -1;
        if (mp[a[i] - 'a'] < mp[b[i] - 'a'])
            return 1;
        i++;
    }
    if (i >= a.length())
        return 1;
    if (i >= b.length())
        return -1;
    return 0;
}

bool isAlienSorted(vector<string> &words, string order)
{
    map<int, int> mp;

    for (int i = 0; i < order.size(); i++)
    {
        mp[order[i] - 'a'] = i;
    }

    for (int i = 0; i < words.size() - 1; i++)
    {
        if (compareAlien(words[i], words[i + 1], mp) == -1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";

    if (isAlienSorted(words, order))
        cout << "true";
    else
        cout << "false";

    return 0;
}