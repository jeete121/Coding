#include <bits/stdc++.h>
using namespace std;

//comparator used for sorting
bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void maximimeIt(long long n, long long k, vector<pair<long long, long long>> &v)
{
    sort(v.begin(), v.end(), cmp);
    set<long long> st;
    vector<long long> v1;
    for (long long i = 0; i < n; i++)
    {
        long long len = st.size();
        st.insert(v[i].first);
        if (len != st.size())
        {
            k = k - v[i].second;
            if (k < 0)
            {

                break;
            }
            else
                v1.push_back(v[i].first);
        }
    }
    if (v1.size() == 0)
        cout << -1 << "\n";
    else
    {
        sort(v1.begin(), v1.end());
        for (long long i = 0; i < v1.size() - 1; i++)
            cout << v1[i] << ",";
        cout << v1[v1.size() - 1];
    }
}
int main()
{

    long long n = 3, k = 6;
    vector<pair<long long, long long>> v = {{1, 1}, {2, 2}, {3, 3}};

    maximimeIt(n, k, v);

    return 0;
}