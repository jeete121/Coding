#include <bits/stdc++.h>
using namespace std;

string reverseStr(string s, int k)
{
    int n = s.size();
    if (n == 0 || k == 0)
        return s;
    int i = 0;
    while (i < n)
    {
        reverse(s.begin() + i, s.begin() + min(i + k, n));
        i += 2 * k;
    }
    return s;
}

int main()
{
    string s = "abcdefg";
    int k = 2;
    cout << reverseStr(s, k);
    return 0;
}