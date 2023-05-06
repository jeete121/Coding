#include <bits/stdc++.h>
using namespace std;

vector<int> diStringMatch(string S)
{
    int l = 0, r = S.size();
    vector<int> res;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'I')
            res.push_back(l++);
        else
            res.push_back(r--);
    }
    res.push_back(l);
    return res;
}

int main()
{
    string str = "IDID";
    vector<int> DI = diStringMatch(str);
    cout << "[";
    for (int i = 0; i < DI.size() - 1; i++)
        cout << DI[i] << ",";
    cout << DI[DI.size() - 1] << "]";
    return 0;
}