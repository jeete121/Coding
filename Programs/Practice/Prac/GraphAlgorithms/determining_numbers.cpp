#include <bits/stdc++.h>
using namespace std;

void detemineNumbers(int n, int a[])
{
    sort(a, a + n);
    int i = 0;
    while (i < n)
    {
        if (i != n - 1 && a[i] == a[i + 1])
        {
            i += 2;
        }
        else
        {
            cout << a[i] << " ";
            i++;
        }
    }
}
int main()
{
    int n = 8;
    int a[n] = {1, 2, 3, 4, 5, 5, 3, 4};

    detemineNumbers(n, a);
    return 0;
}