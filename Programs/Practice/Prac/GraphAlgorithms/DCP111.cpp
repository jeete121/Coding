#include <bits/stdc++.h>
using namespace std;

vector<int> getAnagrams(string w, string str)
{

    vector<int> indexList;
    int n = str.size() - w.size() + 1;

    for (int i = 0; i < n; ++i)
    {
        string subStr = str.substr(i, w.size());
        int total = w.size();
        for (int j = 0; j < w.size(); ++j)
        {
            int index = subStr.find(w[j]);
            if (index != string::npos)
            {

                subStr.replace(index, 1, "");
                total--;
            }
        }
        if (total == 0)
        {
            indexList.push_back(i);
        }
    }
    return indexList;
}

int main()
{

    string w = "ab";
    string str = "abxaba";
    vector<int> res = getAnagrams(w, str);

    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {

        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";
    return 0;
}