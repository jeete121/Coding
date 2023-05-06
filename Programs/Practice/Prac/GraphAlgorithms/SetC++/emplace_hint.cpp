#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(4);
    st.insert(2);
    st.insert(3);
    st.insert(1);

    st.emplace_hint(st.begin(), 5);

    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it << " ";

    return 0;
}
/*
Attempts to insert an element into the %set.

Parameters:
__pos – An iterator that serves as a hint as to where the element 
should be inserted.
__args – Arguments used to generate the element to be inserted.

Returns:
An iterator that points to the element with key equivalent to 
the one generated from __args (may or may not be the element itself).
 This function is not concerned about whether the insertion took place,
  and thus does not return a boolean like the single-argument emplace()
   does. Note that the first parameter is only a hint and can potentially
    improve the performance of the insertion process. 
File: stl_set.h
*/