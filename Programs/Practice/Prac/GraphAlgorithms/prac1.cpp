
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec;
    vec.assign(4, 1);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

    return 0;
}

/*
Assigns a given value to a %vector.

Parameters:
__n – Number of elements to be assigned.
__val – Value to be assigned. 
This function fills a %vector with __n copies of the given value.
 Note that the assignment completely changes the %vector and that 
 the resulting %vector's size is the same as the number of elements 
 assigned.

 File: stl_vector.h
 */