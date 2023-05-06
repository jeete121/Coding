
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    //read the last element of the vector
    cout << vec.back() << "\n";

    //update or write to the last element of
    //the vector
    vec.back() = 10;

    cout << vec.back() << "\n";
    return 0;
}

/*
Returns a read/write reference to the data at the last
element of the %vector.

File: stl_vector.h
 */