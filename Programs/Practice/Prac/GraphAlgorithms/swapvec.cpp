#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec1 = {1, 2, 3, 4};

    vector<int> vec2 = {5, 4, 3, 2, 1};

    vec1.swap(vec2);

    for (int i = 0; i < vec1.size(); i++)
        cout << vec1[i] << " ";

    cout << "\n";
    for (int i = 0; i < vec2.size(); i++)
        cout << vec2[i] << " ";
    
    return 0;
}
/*
Swaps data with another %vector.

Parameters:
__x – A %vector of the same element and allocator types. 
This exchanges the elements between two vectors in constant 
time. (Three pointers, so it should be quite fast.) Note 
that the global std::swap() function is specialized such 
that std::swap(v1,v2) will feed to this function. Whether
the allocators are swapped depends on the allocator traits.

File: stl_vector.h
*/