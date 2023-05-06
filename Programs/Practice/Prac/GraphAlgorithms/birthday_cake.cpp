#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4, i, large_no, large;

    long int a[n] = {3, 2, 1, 3};

    large = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > large)
        {
            large = a[i];
        }
    }
    large_no = 0;
    for (i = 0; i < n; i++)
    {
        {
            if (a[i] == large)
            {
                large_no++;
            }
        }
    }
    cout << large_no;
    return 0;
}
