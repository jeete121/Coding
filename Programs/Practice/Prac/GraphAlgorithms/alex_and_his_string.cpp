#include <bits/stdc++.h>
using namespace std;

string alexString(string s, int k)
{

    int n = s.size();
    string X = "";
    priority_queue<char, vector<char>, greater<char>> q;
    for (int i = 0; i < k; i++)
        q.push(s[i]);
    string res = "";
    for (int i = k; i < n; i++)
    {
        char c = q.top();
        q.pop();
        q.push(s[i]);
        res += c;
    }
    while (!q.empty())
    {
        char c = q.top();
        q.pop();
        res += c;
    }
    return res;
}
int main()
{

    string s = "hackerearth";

    int k = 3;

    cout << alexString(s, k) << "\n";

    return 0;
}