#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 3, 4, 5};

    //insert element after first element
    //of the vector
    vec.insert(vec.begin() + 1, 2);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    

    return 0;
}
/*
Inserts given rvalue into %vector before specified iterator.

Parameters:
__position – A const_iterator into the %vector.
__x – Data to be inserted.

Returns:
An iterator that points to the inserted data.
 This function will insert a copy of the given 
 rvalue before the specified location. Note that 
 this kind of operation could be expensive for a %vector 
and if it is frequently used the user should consider using std::list.

*/