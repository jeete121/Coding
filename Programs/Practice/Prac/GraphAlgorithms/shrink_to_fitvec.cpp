#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec;
    for (int i = 0; i < 5; i++)
        vec.push_back(i + 1);

    cout << vec.capacity() << " " << vec.size() << "\n";

    vec.shrink_to_fit();

    cout << vec.capacity() << " " << vec.size() << "\n";
 
    return 0;
}
/*
A non-binding request to reduce capacity() to size().

File: stl_vector.h
*/