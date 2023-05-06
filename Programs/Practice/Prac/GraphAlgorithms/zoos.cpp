#include <bits/stdc++.h>
using namespace std;

string zoos(string s)
{

    int n = s.size();
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'z')
            x++;
        else
            break;
    }
    int y = n - x;
    if (2 * x == y)
        return "Yes";
    else
        return "No";
}
int main()
{
    string s = "zzzoooooo";

    cout << zoos(s) << "\n";

    return 0;
}