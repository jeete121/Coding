#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};

    int *it = vec.data();

    for (int i = 0; i < vec.size(); i++)
        cout << *it++ << " ";


    return 0;
}
/*
Returns a pointer such that [data(), data() + size()) is a valid
range. For a non-empty %vector, data() == &front().

File: stl_vector.h
*/