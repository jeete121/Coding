#include <bits/stdc++.h>
using namespace std;

vector<string> uncommonFromSentences(string A, string B)
{
    // set<string> st;
    int i = 0;
    int n = A.size();
    int m = B.size();
    map<string, int> mp;
    while (i < n)
    {
        string str = "";
        while (i < n && A[i] == ' ')
            i++;
        while (i < n && A[i] != ' ')
        {
            str += A[i];
            i++;
        }
        mp[str]++;
    }
    i = 0;
    while (i < m)
    {
        string str = "";
        while (i < m && B[i] == ' ')
            i++;
        while (i < m && B[i] != ' ')
        {
            str += B[i];
            i++;
        }
        mp[str]++;
    }
    vector<string> res;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == 1)
            res.push_back(it->first);
    }
    return res;
}

int main()
{
    string A = "this apple is sweet";
    string B = "this apple is sour";

    vector<string> res = uncommonFromSentences(A, B);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}