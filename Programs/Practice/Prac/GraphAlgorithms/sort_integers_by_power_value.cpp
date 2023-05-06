#include <bits/stdc++.h>
using namespace std;

//comparator used for sorting
static bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int getKth(int lo, int hi, int k)
{
    vector<pair<int, int>> v;
    for (int i = lo; i <= hi; i++)
    {
        int j = i;
        int p = 0;
        while (j != 1)
        {
            if (j % 2 == 0)
                j = j / 2;
            else
                j = j * 3 + 1;
            p++;
        }
        v.push_back({i, p});
    }
    sort(v.begin(), v.end(), cmp);
    return v[k - 1].first;
}

int main()
{
    int lo = 12, hi = 15, k = 2;
    cout << getKth(lo, hi, k);
    return 0;
}