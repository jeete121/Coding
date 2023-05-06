#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {3, 4, 5};

    vector<int> arr = {28, 35, 4, 54, 11};
    int value = 12;
    st.insert(value);
    st.insert(arr.begin(), arr.end());
    st.insert({234, 345});
    cout << "Set elements are: ";
    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it << " ";
    return 0;
}
/*
1. 

std::pair<std::__detail::_Node_iterator<int, true, false>, 
   bool> std::unordered_set<int>::insert(const int &__x)

Attempts to insert an element into the %unordered_set.

Parameters:
__x – Element to be inserted.

Returns:
A pair, of which the first element is an iterator that points to
 the possibly inserted element, and the second is a bool that is 
 true if the element was actually inserted. This function attempts 
 to insert an element into the %unordered_set. An %unordered_set 
 relies on unique keys and thus an element is only inserted if it 
 is not already present in the %unordered_set. Insertion requires 
 amortized constant time.

File: unordered_set.h
*/

/*
2.
void std::unordered_set<int>::insert<std::vector<int>::iterator>
 (std::vector<int>::iterator __first, std::vector<int>::iterator __last)
+6 overloads

A template function that attempts to insert a range of elements.

Parameters:
__first – Iterator pointing to the start of the range to be inserted.
__last – Iterator pointing to the end of the range. Complexity similar to that of the range constructor.

*/

/*
3.

void std::unordered_set<int>::insert(std::initializer_list<int> __l)
+5 overloads

Attempts to insert a list of elements into the %unordered_set.

Parameters:
__l – A std::initializer_list<value_type> of elements to be
 inserted. Complexity similar to that of the range constructor.
*/