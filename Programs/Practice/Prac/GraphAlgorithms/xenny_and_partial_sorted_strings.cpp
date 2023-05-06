#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> pi;

string partialSortedString(int n, int k,
                           int m, vector<string> &s)
{
    priority_queue<pi, vector<pi>, greater<pi>> q;
    for (int i = 0; i < n; i++)
    {
        if (s[i].size() == m)
            q.push({s[i], i + 1});
        else if (s[i].size() != m)
        {
            string str = "";
            string p = s[i];
            for (int j = 0; j < m; j++)
                str += p[j];
            q.push({str, i + 1});
        }
    }
    int cnt = 0, j = 0;
    while (!q.empty())
    {
        pair<string, int> p1 = q.top();
        q.pop();
        cnt++;
        if (cnt == k)
        {
            j = p1.second;
            break;
        }
    }
    return s[j - 1];
}
int main()
{

    int n = 3, k = 1, m = 3;

    vector<string> s = {"abcdef",
                        "abcaaa",
                        "aabaaa"};

    cout << partialSortedString(n, k, m, s) << "\n";

    return 0;
}