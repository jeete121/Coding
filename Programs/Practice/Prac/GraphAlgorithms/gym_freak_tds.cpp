#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, pair<int, double>> a, pair<int, pair<int, double>> b)
{
    return a.second.second > b.second.second;
}

int gymFreakTDS(int n, int w, int a[], int b[])
{
    vector<pair<int, pair<int, double>>> v;
    for (int i = 0; i < n; i++)
    {
        double x = (double)a[i] / b[i];
        v.push_back(make_pair(a[i], make_pair(b[i], x)));
    }
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (w >= v[i].second.first)
        {
            ans += v[i].first;
            w -= v[i].second.first;
        }
        else
        {
            int x = v[i].first * w;
            ans += x / v[i].second.first;
            w = 0;
            break;
        }
    }
    return ans;
}
int main()
{

    int n = 5, w = 10;

    int a[n] = {1, 3, 2, 1, 3};
    int b[n] = {2, 4, 5, 7, 8};

    cout << gymFreakTDS(n, w, a, b) << "\n";

    return 0;
}