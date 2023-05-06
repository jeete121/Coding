#include <bits/stdc++.h>
using namespace std;

string upUp(string s)
{
    if (s[0] >= 'a' && s[0] <= 'z')
        s[0] = s[0] - 32;
    int i = 1;
    int n = s.size();
    while (i < n - 1)
    {
        while (s[i] == ' ')
            i++;
        if (s[i] >= 'a' && s[i] <= 'z' && s[i - 1] == ' ')
            s[i] = s[i] - 32;
        i++;
    }
    return s;
}
int main()
{
    string s = "Wish you were here";

    cout << upUp(s) << "\n";

    return 0;
}