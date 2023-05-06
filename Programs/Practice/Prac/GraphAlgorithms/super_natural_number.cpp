#include <bits/stdc++.h>
using namespace std;

int superNatural(int n)
{
    int cnt = 0;
    for (int i = 2; i <= 1000000; i++)
    {
        int j = i;
        int res = 1;
        int flag = 0;
        while (j)
        {
            int x = j % 10;
            if (x == 1 || x == 0)
            {
                flag = 1;
                break;
            }
            res *= x;
            j = j / 10;
        }
        if (flag == 0 && res == n)
            cnt++;
    }
    return cnt;
}
int main()
{
    int n = 4;

    cout << superNatural(n);

    return 0;
}