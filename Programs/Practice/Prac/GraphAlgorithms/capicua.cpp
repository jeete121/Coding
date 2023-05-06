#include <bits/stdc++.h>
using namespace std;

void capicua(string x)
{
    int flag = 0;
    for (int i = 0; i < x.size() / 2; i++)
    {
        if (x[i] != x[x.size() - i - 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main()
{
    string x = "8785878";

    capicua(x);

    return 0;
}