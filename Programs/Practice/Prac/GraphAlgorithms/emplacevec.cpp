#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 4, 5};

    auto it = vec.begin();

    it = it + 2;
    vec.emplace(it, 3);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
     
    return 0;
}

/*
Inserts an object in %vector before specified iterator.

Parameters:
__position – A const_iterator into the %vector.
__args – Arguments.

Returns:
An iterator that points to the inserted data. 
This function will insert an object of type T 
constructed with T(std::forward<Args>(args)...) 
before the specified location. Note that this kind
 of operation could be expensive for a  %vector.
*/