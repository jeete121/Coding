#include <bits/stdc++.h>
using namespace std;

int utopianTree(int n)
{
    int h = 1;
    if (n == 0)
    {
        return h;
    }
    else
    {
        for (int j = 1; j <= n; j++)
        {
            if (j & 1)
                h = h * 2;
            else
                h = h + 1;
        }
        return h;
    }
}

int main()
{

    int n = 4;
    cout << utopianTree(n);
    return 0;
}
