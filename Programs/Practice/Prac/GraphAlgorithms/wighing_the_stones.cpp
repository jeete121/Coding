#include <bits/stdc++.h>
using namespace std;

void weighingTheStones(int n, int a[], int b[])
{
    int f[100] = {0}, f1[100] = {0};
    for (int i = 0; i < n; i++)
        f[a[i]]++;
    for (int i = 0; i < n; i++)
        f1[b[i]]++;
    int max1 = INT_MIN;
    int x, y;
    for (int i = 0; i < 100; i++)
    {
        if (f[i] >= max1)
        {
            max1 = f[i];
            x = i;
        }
    }
    max1 = INT_MIN;
    for (int i = 0; i < 100; i++)
    {
        if (f1[i] >= max1)
        {
            max1 = f1[i];
            y = i;
        }
    }
    if (x > y)
        cout << "Rupam\n";
    else if (x == y)
        cout << "Tie\n";
    else
        cout << "Ankit\n";
}
int main()
{

    int n = 6;

    int a[n] = {5, 3, 1, 4, 3, 2};
    int b[n] = {4, 3, 1, 1, 1, 5};

    weighingTheStones(n, a, b);

    return 0;
}