#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(4);
    st.insert(2);
    st.insert(3);
    st.insert(1);

    st.clear();

    cout << st.size() << "\n";

    return 0;
}
/*
Erases all elements in a %set. Note that this function only erases
the elements, and that if the elements themselves are pointers, the
pointed-to memory is not touched in any way. Managing the pointer is
the user's responsibility.

File: stl_set.h
*/