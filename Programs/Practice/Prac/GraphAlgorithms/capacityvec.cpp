
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec;
    for (int i = 1; i <= 5; i++)
        vec.push_back(i);
    cout << vec.capacity() << "\n";

    return 0;
}

/*
Returns the total number of elements that the %vector can
hold before needing to allocate more memory.

File: stl_vector.h
 */