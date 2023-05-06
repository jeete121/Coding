#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(4);
    st.insert(2);
    st.insert(3);
    st.insert(1);

    set<int>::reverse_iterator it = st.crbegin();

    cout << *it << "\n";

    return 0;
}
/*
Returns a read-only (constant) iterator that points to the last
element in the %set. Iteration is done in descending order according
to the keys.

File: stl_set.h
*/