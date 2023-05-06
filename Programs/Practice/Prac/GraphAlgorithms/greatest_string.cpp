#include <bits/stdc++.h>
using namespace std;

string greatestString(string s, int q)
{
    int i = 0;
    int n = s.size();
    while (q && i < n)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            s[i] = s[i] + 1;
            q--;
        }
        i++;
    }
    return s;
}
int main()
{
    string s = "abcde";

    int q = 3;

    cout << greatestString(s, q) << "\n";

    return 0;
}