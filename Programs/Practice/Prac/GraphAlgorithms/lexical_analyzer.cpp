#include <bits/stdc++.h>
using namespace std;

int lexicalAnalyzer(int n, vector<string> &v)
{
    set<string> st;
    for (int i = 0; i < n; i++)
    {
        string x = "";
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] != '=' && v[i][j] != ' ')
            {
                x += v[i][j];
            }
            if (v[i][j] == '=')
            {
                st.insert(x);
            }
        }
    }
    return st.size();
}
int main()
{
    int n = 2;
    vector<string> v = {"foo = 3;", "bar = 4;"};

    cout << lexicalAnalyzer(n, v) << "\n";
    return 0;
}