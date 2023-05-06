#include <bits/stdc++.h>
using namespace std;

bool snakdown(int n, int p, int a[], int q, int b[])
{
    set<int> st;
    for (int i = 0; i < p; i++)
        st.insert(a[i]);

    for (int i = 0; i < q; i++)
        st.insert(b[i]);
    if (st.size() == n)
        return true;
    else
        return false;
}
int main()
{
    int n = 4;

    int p = 3;
    int a[p] = {1, 2, 3};

    int q = 2;
    int b[q] = {2, 4};

    if (snakdown(n, p, a, q, b))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}