#include <bits/stdc++.h>
using namespace std;

void bricksGame(int n)
{
    int i = 1;
    int flag;
    while (n)
    {
        n = n - i;
        if (n <= 0)
        {

            flag = 1;
            break;
        }
        n = n - 2 * i;
        if (n <= 0)
        {
            flag = 0;
            break;
        }
        i++;
    }
    if (flag == 0)
        cout << "Motu\n";
    else
        cout << "Patlu\n";
}
int main()
{
    int n = 13;

    bricksGame(n);

    return 0;
}
