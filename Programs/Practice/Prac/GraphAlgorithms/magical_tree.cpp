#include <bits/stdc++.h>
using namespace std;

int magicalTree(int L, vector<string> &str)
{
    int res = 0, max1 = INT_MIN;
    for (int i = 0; i < L; i++)
    {
        string s = str[i];
        res = 0;
        int n = s.size();
        int x = s[0] - '0', y = s[2] - '0';

        if (s[1] == '-')
            res = x - y;
        else
            res = x + y;

        for (int i = 3; i < n; i += 2)
        {
            if (s[i] == '-')
                res = res - (s[i + 1] - '0');
            else
                res = res + s[i + 1] - '0';
        }

        max1 = max(max1, res);
    }
    return max1;
}
int main()
{
    int L = 4;

    vector<string> str = {"8-6+2+4+3-6+1", "1+1+1+1",
                          "2+3+6+8-9", "2+7+1-6"};

    cout << magicalTree(L, str) << "\n";

    return 0;
}