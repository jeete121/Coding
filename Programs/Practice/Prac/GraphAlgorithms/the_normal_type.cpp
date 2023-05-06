#include <bits/stdc++.h>
using namespace std;

long long theNormalType(long long n, long long a[])
{
    set<long long> st;
    for (long long i = 0; i < n; i++)
        st.insert(a[i]);
    long long j = 0;
    set<long long> st1;
    map<long long, long long> mp;
    long long cnt = 0;
    for (long long i = 0; i < n; i++)
    {
        j = max(j, i);
        while (j < n && st.size() > st1.size())
        {
            mp[a[j]]++;
            if (mp[a[j]] >= 1)
                st1.insert(a[j]);
            j++;
        }
        if (st.size() == st1.size())
            cnt += n - j + 1;
        mp[a[i]]--;
        if (mp[a[i]] == 0)
            st1.erase(a[i]);
    }
    return cnt;
}
int main()
{

    long long n = 5;

    long long a[n] = {1, 2, 2, 1, 1};

    cout << theNormalType(n, a) << "\n";

    return 0;
}