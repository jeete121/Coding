#include <bits/stdc++.h>
using namespace std;

void printPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n - i; j++)
            cout << " ";

        int j = 1, k = 2 * i - 1;

        while (j <= 2 * i - 1)
        {
            if (j <= k)
            {
                cout << j << " ";
            }
            else
            {
                cout << k << " ";
            }
            j++;
            k--;
        }

        cout << "\n";
    }
}

int main()
{
    int n = 4;

    printPattern(n);

    return 0;
}