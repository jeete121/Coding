#include <bits/stdc++.h>
using namespace std;

int oneStringNoTrouble(string s)
{

    int n = s.size();
    int i = 0;
    int ans = INT_MIN;
    while (i < n)
    {
        int cnt = 1;
        while (i < n - 1 && s[i] != s[i + 1])
        {
            cnt++;
            i++;
        }
        ans = max(ans, cnt);
        i++;
    }
    return ans;
}
int main()
{
    string s = "ab";

    cout << oneStringNoTrouble(s) << "\n";

    return 0;
}