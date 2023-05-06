#include <bits/stdc++.h>
using namespace std;

int countWhiteSpaces(string s)
{
    int n = s.size(), i = 0;
    int cnt = 0;
    while (i < n)
    {
        while (i < n && (s[i] == ' '))
        {
            cnt++;
            i++;
        }
        i++;
    }
    return cnt;
}
int main()
{
    string s = "Hello World";

    cout << countWhiteSpaces(s) << "\n";

    return 0;
}