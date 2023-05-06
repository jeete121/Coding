#include <bits/stdc++.h>
using namespace std;

long long helpRoomMate(long long n)
{
    long long cnt = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            cnt++;
            n = n - 1;
        }
        else
            n = n / 2;
    }
    return cnt;
}
int main()
{

    long long n = 4;

    cout << helpRoomMate(n) << "\n";

    return 0;
}
