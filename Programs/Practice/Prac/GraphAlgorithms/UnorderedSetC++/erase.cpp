#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {9, 5, 6, 34, 45, 78, 12};

    unordered_set<int>::iterator it = st.begin();

    //erase by position
    st.erase(it);

    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it << " ";
    return 0;
}
/*
std::unordered_set<int>::iterator 
std::unordered_set<int>::erase(std::unordered_set<int>::iterator __position)

+3 overloads

LWG 2059.

File: unordered_set.h
*/

/*
2

std::size_t std::unordered_set<int>::erase(const int &__x)
+3 overloads

Erases elements according to the provided key.

Parameters:
__x – Key of element to be erased.

Returns:
The number of elements erased. This function erases all the elements 
located by the given key from an %unordered_set. For an %unordered_set 
the result of this function can only be 0 (not present) or 1 (present).
 Note that this function only erases the element, and that if 
 the element is itself a pointer, the pointed-to memory is not
  touched in any way. Managing the pointer is the user's responsibility

*/

/*
3

std::unordered_set<int>::iterator std::unordered_set<int>::erase(std::unordered_set<int>::const_iterator __first, std::unordered_set<int>::const_iterator __last)
+3 overloads

Erases a [__first,__last) range of elements from an %unordered_set.
Parameters:
__first – Iterator pointing to the start of the range to be erased.
__last – Iterator pointing to the end of the range to be erased.

Returns:
The iterator __last. This function erases a sequence of elements from 
an %unordered_set. Note that this function only erases the element, 
and that if the element is itself a pointer, the pointed-to memory
 is not touched in any way. Managing the pointer is the user's responsibility.
*/