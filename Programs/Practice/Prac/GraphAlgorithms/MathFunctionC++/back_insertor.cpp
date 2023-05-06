#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3};

    back_inserter(vec) = 10;

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

    return 0;
}
/*
template<class _Container> std::back_insert_iterator<_Container> 
 std::back_inserter(_Container &__x)

Parameters:
__x – A container of arbitrary type.

Returns:
An instance of back_insert_iterator working on __x. This wrapper
 function helps in creating back_insert_iterator instances. Typing 
 the name of the %iterator requires knowing the precise full type 
 of the container, which can be tedious and impedes generic programming.
  Using this function lets you take advantage of automatic template
   parameter deduction, making the compiler match the correct types 
   for you.

File: stl_iterator.h
*/