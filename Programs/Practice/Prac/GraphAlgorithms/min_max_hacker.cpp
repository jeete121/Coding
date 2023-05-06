#include <bits/stdc++.h>
using namespace std;

bool minMax(int n, int a[])
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    sort(a, a + n);
    int min1 = a[0], max1 = a[n - 1];
    int flag = 0;
    for (int i = min1; i <= max1; i++)
    {
        if (st.find(i) == st.end())
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return true;
    else
        return false;
}
int main()
{
    int n = 6;

    int a[n] = {4, 2, 1, 3, 5, 6};

    if (minMax(n, a))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}