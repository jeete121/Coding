#include <bits/stdc++.h>
using namespace std;

string reverseString(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        swap(s[i], s[s.size() - 1 - i]);
    }
    return s;
}
int main()
{

    string s = "ab";

    cout << reverseString(s) << "\n";

    return 0;
}