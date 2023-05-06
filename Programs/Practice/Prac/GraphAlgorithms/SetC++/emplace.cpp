#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(4);
    st.insert(2);
    st.insert(3);
    st.insert(1);

    st.emplace(6);

    cout << st.size() << "\n";

    return 0;
}
/*
Attempts to build and insert an element into the %set.

Parameters:
__args – Arguments used to generate an element.

Returns:
A pair, of which the first element is an iterator that points to the possibly inserted element, and the second is a bool that is true if the element was actually inserted. This function attempts to build and insert an element into the %set. A %set relies on unique keys and thus an element is only inserted if it is not already present in the %set. Insertion requires logarithmic time.

File: stl_set.h
*/