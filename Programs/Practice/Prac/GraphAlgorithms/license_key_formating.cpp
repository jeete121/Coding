#include <bits/stdc++.h>
using namespace std;

string licenseKeyFormatting(string S, int K)
{
    int n = S.size();
    string res = "";
    int cnt = 0;
    vector<char> v;
    for (int i = 0; i < n; i++)
        if (S[i] != '-')
            v.push_back(S[i]);
    if (v.size() == 0)
        return res;
    for (int i = 0; i < v.size(); i++)
        if (v[i] >= 'a' && v[i] <= 'z')
            v[i] = v[i] - 32;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        res += v[i];
        cnt++;
        if (cnt == K)
        {
            cnt = 0;
            res += '-';
        }
    }
    if (res[res.size() - 1] == '-')
        res.erase(res.begin() + res.size() - 1);
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string S = "5F3Z-2e-9-w";
    int K = 4;

    cout << licenseKeyFormatting(S, K);

    return 0;
}