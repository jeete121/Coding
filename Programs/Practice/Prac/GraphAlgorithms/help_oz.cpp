#include <bits/stdc++.h>
using namespace std;

void helpOZ(int m, int a[])
{
    int max1 = 0;
    for (int i = 0; i < m; i++)
    {

        if (a[i] > max1)
            max1 = a[i];
    }
    for (int i = 2; i < max1 / 2; i++)
    {

        int flag = 0;
        int x = a[0] % i;
        for (int j = 1; j < m; j++)
        {
            if (a[j] % i != x)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << i << " ";
    }
}
int main()
{

    int m = 3;

    int a[m] = {38, 6, 34};

    helpOZ(m, a);

    return 0;
}