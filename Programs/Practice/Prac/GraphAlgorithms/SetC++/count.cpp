#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(4);
    st.insert(2);
    st.insert(3);
    st.insert(1);
    st.insert(1);

    cout << st.count(1) << "\n";

    return 0;
}
/*
Finds the number of elements.

Parameters:
__x – Element to located.

Returns:
Number of elements with specified key. This function only
 makes sense for multisets; for set the result will either 
 be 0 (not present) or 1 (present).

File: stl_set.h
*/