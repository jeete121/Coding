#include <bits/stdc++.h>
using namespace std;

int spaceCakewalk(int n, int a[])
{
    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(a[i]);
    int len = st.size();
    return len + 1;
}

int main()
{

    int n = 6;

    int a[n] = {1, 2, 1, 2, 3, 5};

    cout << spaceCakewalk(n, a) << "\n";
    return 0;
}