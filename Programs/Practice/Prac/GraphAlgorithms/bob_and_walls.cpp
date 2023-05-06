#include <bits/stdc++.h>
using namespace std;

int bobAndWalls(int n, int a[])
{

    int cnt = 1, max1 = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max1)
        {
            cnt++;
            max1 = a[i];
        }
    }
    return cnt;
}
int main()
{
    int n = 5;

    int a[n] = {1, 3, 2, 5, 4};

    cout << bobAndWalls(n, a) << "\n";

    return 0;
}