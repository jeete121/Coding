#include <bits/stdc++.h>
using namespace std;

void gokiBreakup(int n, int x, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        int y = arr[i];
        if (y >= x)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
int main()
{
    int n = 5;
    int x = 100;
    int arr[] = {110, 130, 90, 100, 45};

    gokiBreakup(n, x, arr);

    return 0;
}