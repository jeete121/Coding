#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 3;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int k = 0; k < 2 * i - 1; k++)
            cout << "*";
        cout << "\n";
    }
    cout << "\n";

    return 0;
}