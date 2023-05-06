#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    vec.erase(vec.begin());

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

    return 0;
}
/*
Remove element at given position.

Parameters:
__position – Iterator pointing to element to be erased.

Returns:
An iterator pointing to the next element (or end()). 
This function will erase the element at the given position
 and thus shorten the %vector by one. Note This operation 
 could be expensive and if it is frequently used the user 
 should consider using std::list. The user is also cautioned
  that this function only erases the element, and that if 
  the element is itself a pointer, the pointed-to memory is not 
touched in any way. Managing the pointer is the user's responsibility.
*/