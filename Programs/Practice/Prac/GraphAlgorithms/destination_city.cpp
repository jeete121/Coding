#include <bits/stdc++.h>
using namespace std;

string destCity(vector<vector<string>> &paths)
{
    set<string> st;
    int n = paths.size();
    for (int i = 0; i < n; i++)
        st.insert(paths[i][0]);
    string res;
    for (int i = 0; i < n; i++)
    {
        if (st.find(paths[i][1]) == st.end())
        {
            res = paths[i][1];
            break;
        }
    }
    return res;
}

int main()
{
    vector<vector<string>> paths = {{"London", "New York"},
                                    {"New York", "Lima"},
                                    {"Lima", "Sao Paulo"}};

    cout << destCity(paths);
    return 0;
}