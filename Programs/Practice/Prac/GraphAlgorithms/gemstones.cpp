#include <bits/stdc++.h>
using namespace std;

int gemstones(vector<string> str)
{

    int n = str.size();
    set<char> st;
    vector<char> res;
    for (int i = 0; i < str[0].size(); i++)
        st.insert(str[0][i]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < str[i].size(); j++)
        {
            if (st.find(str[i][j]) != st.end())
            {
                res.push_back(str[i][j]);
            }
        }
        st.clear();
        for (int k = 0; k < res.size(); k++)
            st.insert(res[k]);
        res.clear();
    }
    return st.size();
}

int main()
{
    int n = 3;

    vector<string> str = {"abcdde", "bacc", "eeabg"};
    cout << gemstones(str);
    return 0;
}
