#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert({1, 19, 5, 2});

    set<int>::iterator it = st.lower_bound(3);

    cout << *it << "\n";

    return 0;
}
/*

Finds the beginning of a subsequence matching given key.

Parameters:
__x – Key to be located.

Returns:
Iterator pointing to first element equal to or greater than key, 
or end(). This function returns the first element of a subsequence 
of elements that matches the given key. If unsuccessful it returns 
an iterator pointing to the first element that has a greater value 
than given key or end() if no such element exists.
*/