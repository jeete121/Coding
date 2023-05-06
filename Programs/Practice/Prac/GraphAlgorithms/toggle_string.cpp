#include <bits/stdc++.h>
using namespace std;

string toggleString(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
        else
            s[i] = s[i] - 32;
    }
    return s;
}
int main()
{
    string s = "abcdE";

    cout << toggleString(s) << "\n";

    return 0;
}