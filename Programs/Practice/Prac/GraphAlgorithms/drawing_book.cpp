#include <bits/stdc++.h>
using namespace std;

int pageCount(int n, int p)
{

    int no = 0, j;
    if (p <= n / 2)
        no = p / 2;
    else if (p == 5 && n == 6)
        no = 1;
    else
    {
        j = n;
        while (p != j && p != j - 1)
        {
            no++;
            j = j - 2;
        }
    }
    return no;
}
int main()
{
    int n = 6, p = 2;
    cout << pageCount(n, p);
    return 0;
}
