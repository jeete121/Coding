#include <bits/stdc++.h>
using namespace std;

int setBits(int n)
{
    int res = 0;
    while (n)
    {
        res++;
        n = n & (n - 1);
    }
    return res;
}

vector<int> v;
void initialize()
{

    for (int i = 1; i <= 1000000; i++)
    {
        int x = setBits(i);
        int y = log2(i) + 1 - x;
        int g = __gcd(x, y);
        if (g == 1)
            v.push_back(i);
    }
    for (int i = 1000001;; i++)
    {
        int x = setBits(i);
        int y = log2(i) + 1 - x;
        int g = __gcd(x, y);
        if (g == 1)
            v.push_back(i);
        if (v.size() >= 627509)
            break;
    }
}
int main()
{

    int n = 5;

    initialize();
    cout << v[n - 1] << "\n";
    return 0;
}