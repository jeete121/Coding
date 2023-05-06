#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {9, 4};

    st.emplace(10);
    cout << st.size() << "\n";

    return 0;
}
/*
template<class... _Args> std::pair<std::__detail::_Node_iterator<int, true, false>, bool> std::unordered_set<int>::emplace(_Args &&...__args)

Attempts to build and insert an element into the %unordered_set.

Parameters:
__args – Arguments used to generate an element.

Returns:
A pair, of which the first element is an iterator that
 points to the possibly 
inserted element, and the second is a bool that is true if 
the element was actually inserted. This function attempts 
to build and insert an element into the %unordered_set.
 An %unordered_set relies on unique keys and thus an 
 element is only inserted if it is not already present 
 in the %unordered_set. Insertion requires amortized constant time.

File: unordered_set.h
*/