#include <bits/stdc++.h>
using namespace std;

int beerAndString(string s, int n, vector<string> &arr)
{
    int f[26] = {0};
    for (int i = 0; i < s.size(); i++)
        f[s[i] - 'a']++;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        string str = arr[i];

        int f1[26] = {0};
        int flag = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                f1[str[i] - 'a']++;
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (int i = 0; i < 26; i++)
            {
                if (f1[i] > 0)
                {
                    if (f1[i] > f[i])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0)
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    string s = "abcd";
    int n = 2;
    vector<string> arr = {"ab", "ef"};

    cout << beerAndString(s, n, arr) << "\n";

    return 0;
}