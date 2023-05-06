#include <bits/stdc++.h>
using namespace std;

long strangeCounter(long t)
{
    long cnt = 3;
    while (t > cnt)
    {
        t = t - cnt;
        cnt = cnt * 2;
    }
    return cnt - t + 1;
}

int main()
{
    long t = 4;

    long result = strangeCounter(t);
    cout << result << "\n";

    return 0;
}
