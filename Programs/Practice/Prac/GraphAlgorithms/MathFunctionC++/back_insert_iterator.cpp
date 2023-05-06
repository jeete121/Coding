#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    back_insert_iterator<vector<int>>::container_type arr = vec;

      for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}
/*
template<class _Container> class std::back_insert_iterator<_Container>

Turns assignment into insertion. These are output iterators, 
constructed from a container-of-T. Assigning a T to the iterator
 appends it to the container using push_back. Tip: Using the 
 back_inserter function to create these iterators can save typing.

Parameters
_Cont
The container that the back_insert_iterator is to insert an element into.

Return Value
A back_insert_iterator for the parameter container.

 Returns:A reference to the element inserted at the back of the container.

File: stl_iterator.h
*/