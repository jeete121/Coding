#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert({6, 2, 1, 8});

    set<int>::iterator it = st.upper_bound(4);

    cout << *it << "\n";

    return 0;
}
/*
Finds the end of a subsequence matching given key.

Parameters:
__x – Key to be located.

Returns:
Iterator pointing to the first element greater than key, or end().
*/