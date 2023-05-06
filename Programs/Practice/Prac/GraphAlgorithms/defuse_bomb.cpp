#include <bits/stdc++.h>
using namespace std;

vector<int> decrypt(vector<int> &code, int k)
{
    vector<int> res;
    int n = code.size();
    if (k == 0)
    {
        for (int i = 0; i < code.size(); i++)
            res.push_back(0);
    }
    else if (k > 0)
    {
        int p = k;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            k = p;
            for (int j = i + 1; j < n && k > 0; j++)
            {
                k--;
                sum += code[j];
            }
            for (int j = 0; k > 0; j++)
            {
                sum += code[j];
                k--;
            }
            res.push_back(sum);
        }
    }
    else if (k < 0)
    {
        int p = -k;
        for (int i = 0; i < n; i++)
        {
            k = p;
            int sum = 0;
            for (int j = i - 1; j >= 0 && k > 0; j--)
            {
                sum += code[j];
                k--;
            }
            for (int j = n - 1; j >= 0 && k > 0; j--)
            {
                sum += code[j];
                k--;
            }
            res.push_back(sum);
        }
    }
    return res;
}

int main()
{
    vector<int> code = {5, 7, 1, 4};
    int k = 3;
    vector<int> ans = decrypt(code, k);
    cout << "[";
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ",";
    cout << ans[ans.size() - 1] << "]";
    return 0;
}