#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert({1, 2, 4, 3});

    cout << st.max_size() << "\n";

    return 0;
}
/*
Returns the maximum size of the %set.

File: stl_set.h
*/