#include <bits/stdc++.h>
using namespace std;

int countNumbers(int n, string s)
{

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            while (i < n && s[i] >= '0' && s[i] <= '9')
                i++;
            cnt++;
        }
    }
    return cnt;
}
int main()
{

    int n = 26;

    string s = "sadw96aeafae4awdw2wd100awd";

    cout << countNumbers(n, s) << "\n";

    return 0;
}