#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> largeGroupPositions(string s)
{
    vector<vector<int>> answer;

    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i - 1])
            if (i + 1 < s.size() && s[i + 1] == s[i])
            {
                int j = i + 1;
                while (j < s.size() && s[j] == s[i])
                    {
                        j++;
                    }
                answer.push_back({i - 1, j - 1});
                i = j;
            }

    return answer;
}

int main()
{
    string s = "abbxxxxzzy";

    vector<vector<int>> res = largeGroupPositions(s);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j != res[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}