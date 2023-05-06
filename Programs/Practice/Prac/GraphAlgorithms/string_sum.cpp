#include <bits/stdc++.h>
using namespace std;

int stringSum(string s)
{
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += s[i] - 'a' + 1;
    }
    return ans;
}
int main()
{
    string s = "aba";

    cout << stringSum(s) << "\n";

    return 0;
}