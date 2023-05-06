#include <bits/stdc++.h>
using namespace std;

vector<long long> rainSound(long long l, long long r, long long s)
{
    vector<long long> res;
    long long min1, max1;
    if (l % s == 0)
        min1 = l / s;
    else
        min1 = l / s + 1;
    max1 = r / s;
    if (min1 > max1)
    {
        res.push_back(-1);
        res.push_back(-1);
    }
    else
    {
        res.push_back(min1);
        res.push_back(max1);
    }

    return res;
}
int main()
{
    long long l = 5, r = 10, s = 3;

    vector<long long> res = rainSound(l, r, s);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}