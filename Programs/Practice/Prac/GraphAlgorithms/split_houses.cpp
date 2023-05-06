#include <bits/stdc++.h>
using namespace std;

void splitHouses(int n, string s)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'H' && s[i + 1] == 'H')
        {
            flag = 1;
            break;
        }
        else if (s[i] == '.')
            s[i] = 'B';
    }
    if (s[n - 1] == '.')
        s[n - 1] = 'B';
    if (flag == 0)
    {
        cout << "YES\n";
        cout << s << "\n";
    }
    else
        cout << "NO\n";
}
int main()
{
    int n = 5;

    string s = "H...H";

    splitHouses(n, s);
    return 0;
}