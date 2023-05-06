#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    vec.resize(10);

    cout << vec.size() << "\n";
    
    return 0;
}
/*
Resizes the %vector to the specified number of elements.

Parameters:
__new_size – Number of elements the %vector should contain. 
This function will %resize the %vector to the specified number
 of elements. If the number is smaller than the %vector's 
 current size the %vector is truncated, otherwise default 
 constructed elements are appended.
*/