
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    cout << vec.at(1) << "\n";

    return 0;
}

/*
Provides access to the data contained in the %vector.

It return the value at given position in the vector.

if(position is more than number of elements in the vector)

terminate called after throwing an instance of 'std::out_of_range'

File: stl_vector.h
 */