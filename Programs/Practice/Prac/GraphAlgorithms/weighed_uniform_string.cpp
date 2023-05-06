#include <bits/stdc++.h>
using namespace std;

vector<string> weightedUniformStrings(string s, vector<int> queries)
{
    vector<string> res;
    set<int> st;
    st.insert(s[0] - 'a' + 1);
    for (int i = 1; i < s.size(); i++)
    {

        if (s[i] == s[i - 1])
        {
            int k = 2;
            while (s[i] == s[i - 1])
            {
                int x = s[i] - 'a' + 1;
                st.insert(k * x);
                i++;
                k++;
            }
            st.insert(s[i] - 'a' + 1);
        }
        else
            st.insert(s[i] - 'a' + 1);
    }
    for (int i = 0; i < queries.size(); i++)
    {
        if (st.find(queries[i]) != st.end())
            res.push_back("Yes");
        else
            res.push_back("No");
    }
    return res;
}

int main()
{

    string s = "abccddde";

    int queries_count = 6;
    vector<int> queries = {1, 3, 12, 5, 9, 10};

    vector<string> result = weightedUniformStrings(s, queries);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
