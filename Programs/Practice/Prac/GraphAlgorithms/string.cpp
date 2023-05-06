#include <bits/stdc++.h>
using namespace std;

int stringFreqCount(int n, string s)
{
    int f[26] = {0};
    for (int i = 0; i < n; i++)
        f[s[i] - 'a']++;
    int max1 = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        if (f[i] > max1)
            max1 = f[i];
    }
    return n - max1;
}
int main()
{
    int n = 5;

    string s = "aaaaa";

    cout << stringFreqCount(n, s) << "\n";
    return 0;
}