#include <bits/stdc++.h>
using namespace std;

void tryFirst(int a)
{
    int b = a;
    int c = a;
    int n = log2(a) + 1;
    for (int i = 0; i < n; i++)
    {
        c = c ^ (1 << i);
    }
    cout << b << " " << c << "\n";
}
int main()
{
    int a = 7;

    tryFirst(a);

    return 0;
}