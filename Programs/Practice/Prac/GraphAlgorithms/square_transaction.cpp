#include <bits/stdc++.h>
using namespace std;

int squareInTrinagle(int n, int b)
{
    int i = 1;
    int cnt = 1;
    int ans = 0;
    while (true)
    {
        if (2 * n <= b)
        {
            ans += cnt * i;
            i++;
            b = b - n;
        }
        else
            break;
    }
    return ans;
}
int main()
{

    int n = 2, b = 5;

    cout << squareInTrinagle(n, b) << "\n";

    return 0;
}