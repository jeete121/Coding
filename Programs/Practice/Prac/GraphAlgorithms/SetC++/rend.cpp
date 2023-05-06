#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert({1, 4, 3, 2});

    set<int>::const_reverse_iterator it = st.rend();

    cout << *it << "\n";

    return 0;
}
/*
Returns a read-only (constant) reverse iterator that points to the
last pair in the %set. Iteration is done in descending order
according to the keys.

File: stl_set.h
*/