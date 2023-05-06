#include <bits/stdc++.h>
using namespace std;

void longestCodingStreak(long long n, vector<string> &s)
{
    long long res = 0;
    long long cnt = 0;
    for (long long i = 0; i < n; i++)
    {
        string str = s[i];
        cnt = 0;
        for (long long j = 0; j < str.size(); j++)
        {
            if (str[j] == 'C')
                cnt++;
            else
            {
                res = max(res, cnt);
                cnt = 0;
            }
        }
        res = max(res, cnt);
    }
    res = max(res, cnt);
    long long res1 = 0;
    long long cnt1 = 0;
    for (long long i = 0; i < n; i++)
    {
        string str = s[i];
        for (long long j = 0; j < str.size(); j++)
        {
            if (str[j] == 'C')
                cnt1++;
            else
            {
                res1 = max(res1, cnt1);
                cnt1 = 0;
            }
        }
    }
    res1 = max(res1, cnt1);
    cout << res << " " << res1 << "\n";
}
int main()
{
    long long n = 4;

    vector<string> s = {"SSSSEEEECCCCEECCCC",
                        "CCCCCSSSSEEECCCCSS",
                        "SSSSSEEESSCCCCCCCS",
                        "EESSSSCCCCCCSSEEEE"};

    longestCodingStreak(n, s);

    return 0;
}