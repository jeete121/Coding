#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(4);
    st.insert(2);
    st.insert(3);
    st.insert(1);

    set<int>::const_iterator it = st.cend();

    cout << *it << "\n";

    return 0;
}
/*
Returns a read-only (constant) iterator that points one past the last
element in the %set. Iteration is done in ascending order according
to the keys.

File: stl_set.h
*/