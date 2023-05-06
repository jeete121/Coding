#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 10, 30};
    vector<int> arr = {4, 5, 60};

    copy(arr.begin(), arr.end(), inserter(vec, vec.begin()));

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

        return 0;
}
/*
Parameters:
__x – A container of arbitrary type.
__i – An iterator into the container.

Returns:
An instance of insert_iterator working on __x. This wrapper function 
helps in creating insert_iterator instances. Typing the name of the 
%iterator requires knowing the precise full type of the container, 
which can be tedious and impedes generic programming. Using this 
function lets you take advantage of automatic template parameter 
deduction, making the compiler match the correct types for you.

File: stl_iterator.h

*/