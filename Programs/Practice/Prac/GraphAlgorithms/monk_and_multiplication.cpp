#include <bits/stdc++.h>
using namespace std;

void multiplication(long long n, long long a[])
{

    priority_queue<long long> q;
    for (long long i = 0; i < n; i++)
    {
        q.push(a[i]);
        if (i < 2)
            cout << -1 << "\n";
        else
        {
            long long x = q.top();
            q.pop();
            long long y = q.top();
            q.pop();
            long long z = q.top();
            q.push(x);
            q.push(y);
            cout << x * y * z << "\n";
        }
    }
}
int main()
{
    long long n = 5;

    long long a[n] = {1, 2, 3, 4, 5};

    multiplication(n, a);

    return 0;
}