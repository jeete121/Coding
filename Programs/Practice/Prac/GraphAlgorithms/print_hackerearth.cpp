#include <bits/stdc++.h>
using namespace std;

int printHackerearth(int n, string s)
{

    int f[26] = {0};
    for (int i = 0; i < n; i++)
        f[s[i] - 'a']++;
    int min1 = INT_MAX;
    min1 = min(min1, f[0] / 2);
    min1 = min(min1, f[2]);
    min1 = min(min1, f[4] / 2);

    min1 = min(min1, f[7] / 2);
    min1 = min(min1, f[10]);
    min1 = min(min1, f[17] / 2);
    min1 = min(min1, f[19]);
    return min1;
}
int main()
{
    int n = 13;

    string s = "aahkcreeatrha";

    cout << printHackerearth(n, s) << "\n";

    return 0;
}