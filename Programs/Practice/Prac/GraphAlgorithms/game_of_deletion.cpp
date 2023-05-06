#include <bits/stdc++.h>
using namespace std;

void gameOfDeletion(int n, int a[], int b[])
{
    int suma = 0, sumb = 0, costa = 0, costb = 0;
    for (int i = 0; i < n; i++)
    {

        suma += a[i];
        costa = costa | a[i];
    }
    for (int i = 0; i < n; i++)
    {

        sumb += b[i];
        costb = costb | b[i];
    }
    int rewarda = suma - costa;
    int rewardb = sumb - costb;
    if (rewarda > rewardb)
        cout << 1 << " " << rewarda - rewardb << "\n";
    else
        cout << 2 << " " << rewardb - rewarda << "\n";
}
int main()
{
    int n = 3;
    int a[n] = {1, 2, 1}, b[n] = {1, 2, 3};

    gameOfDeletion(n, a, b);

    return 0;
}