#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int x1 = 0, v1 = 3, x2 = 4, v2 = 2;
    if ((x2 - x1) * (v2 - v1) < 0 and (x2 - x1) % (v2 - v1) == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}