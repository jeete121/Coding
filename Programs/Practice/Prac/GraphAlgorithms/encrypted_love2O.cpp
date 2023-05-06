#include <bits/stdc++.h>
using namespace std;

string encryptedLove(string s)
{
    int mid;
    if (s.size() & 1)
        mid = s.size() / 2;
    else
        mid = s.size() / 2 - 1;
    if (mid == 0)
        return s.substr(mid);
    return s[mid] + encryptedLove(s.substr(mid + 1)) + encryptedLove(s.substr(0, mid));
}
int main()
{

    int n = 3;

    string s = "abc";
    cout << encryptedLove(s) << "\n";

    return 0;
}