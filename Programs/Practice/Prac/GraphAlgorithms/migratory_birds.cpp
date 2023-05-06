#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n = 6, i, t1 = 0;
    int t2 = 0, t3 = 0, t4 = 0, t5 = 0;
    long int a[n] = {1, 4, 4, 4, 5, 3};
    for (i = 0; i < n; i++)
    {
        if (a[i] == 1)
            t1++;
        if (a[i] == 2)
            t2++;
        if (a[i] == 3)
            t3++;
        if (a[i] == 4)
            t4++;
        if (a[i] == 5)
            t5++;
    }
    if (t1 >= t2 && t1 >= t3 && t1 >= t4 && t1 >= t5)
    {
        cout << "1\n";
    }
    else if (t2 >= t1 && t2 >= t3 && t2 >= t4 && t2 >= t5)
    {
        cout << "2\n";
    }
    else if (t3 >= t1 && t3 >= t2 && t3 >= t4 && t3 >= t5)
    {
        cout << "3\n";
    }
    else if (t4 >= t1 && t4 >= t2 && t4 >= t3 && t4 >= t5)
    {
        cout << "4\n";
    }
    else if (t5 >= t1 && t5 >= t2 && t5 >= t3 && t5 >= t4)
    {
        cout << "5\n";
    }
    return 0;
}
