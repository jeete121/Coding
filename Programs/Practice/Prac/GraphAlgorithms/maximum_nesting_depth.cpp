#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{
    int n = s.size();
    int ans = 0;
    int open = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            open++;
            ans = max(ans, open);
        }
        else if (s[i] == ')')
        {
            open--;
        }
    }
    return ans;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(s);
    return 0;
}