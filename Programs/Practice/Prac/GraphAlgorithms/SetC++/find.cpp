#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    set<int> st;
    st.insert(4);
    st.insert(2);
    st.insert(3);
    st.insert(1);

    set<int>::iterator it = st.find(3);
    cout << *it << "\n";

    return 0;
}
/*
Tries to locate an element in a %set.

Parameters:
__x – Element to be located.

Returns:
Iterator pointing to sought-after element, or end() if not found. This
 function takes a key and tries to locate the element with which the 
 key matches. If successful the function returns an iterator pointing 
 to the sought after element. If unsuccessful it returns the past-the-end 
 ( end() ) iterator.
*/