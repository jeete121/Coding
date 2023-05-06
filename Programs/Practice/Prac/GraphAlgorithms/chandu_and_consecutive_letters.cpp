#include <bits/stdc++.h>
using namespace std;

string consecutiveLetters(string s)
{
    int n = s.size();
    int i = 0;
    string str = "";
    while (i < n)
    {
        while (i < n - 1 && s[i] == s[i + 1])
            i++;
        str += s[i];
        i++;
    }
    return str;
}
int main()
{

    string s = "abb";

    cout << consecutiveLetters(s) << "\n";

    return 0;
}