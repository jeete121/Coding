#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(4);
    st.insert(2);
    st.insert(3);
    st.insert(1);

    //remove 3 from the set
    st.erase(3);

    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it << " ";

    return 0;
}
/*
Erases elements according to the provided key.

Parameters:
__x – Key of element to be erased.

Returns:
The number of elements erased. This function erases all the elements
 located by the given key from a %set. Note that this function only
  erases the element, and that if the element is itself a pointer, 
  the pointed-to memory is not touched in any way. Managing the pointer 
  is the user's responsibility.
*/