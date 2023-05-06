#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {9, 5, 4, 3, 2, 10};

    int x = 4;
    unordered_set<int>::iterator it = st.find(x);

    if (it == st.end())
        cout << "Element is not found\n";
    else
        cout << "Element is found\n";

    return 0;
}
/*
std::unordered_set<int>::iterator std::unordered_set<int>::find(const int &__x)

+1 overload

Tries to locate an element in an %unordered_set.

Parameters:
__x – Element to be located.

Returns:
Iterator pointing to sought-after element, or end() if not found. 
This function takes a key and tries to locate the element 
with which the key matches. If successful the function returns
 an iterator pointing to the sought after element. 
If unsuccessful it returns the past-the-end ( end() ) iterator.
File: unordered_set.h

*/