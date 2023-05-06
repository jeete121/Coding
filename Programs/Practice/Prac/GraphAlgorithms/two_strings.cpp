#include <bits/stdc++.h>
using namespace std;

void twoStrings(string a, string b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{

    string a = "sumit", b = "mitsu";

    twoStrings(a, b);

    return 0;
}