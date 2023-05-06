#include <bits/stdc++.h>
using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
    unordered_map<string, int> ump;
    int n = strings.size();
    int q = queries.size();
    for (int i = 0; i < n; i++)
    {
        ump[strings[i]]++;
    }
    vector<int> v;
    for (int i = 0; i < q; i++)
    {
        if (ump.find(queries[i]) == ump.end())
            v.push_back(0);
        else
            v.push_back(ump[queries[i]]);
    }
    return v;
}

int main()
{
    int n = 3;
    vector<string> str = {"def", "de", "fgh"};

    int q = 3;
    vector<string> queries = {"de", "lmn", "fgh"};
    vector<int> res = matchingStrings(str, queries);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\n";
    }
    return 0;
}
