#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};

    vec.clear();

    cout << vec.size() << "\n";

    return 0;
}
/*
Erases all the elements. Note that this function only erases the
elements, and that if the elements themselves are pointers, the
pointed-to memory is not touched in any way. Managing the pointer is
the user's responsibility.

File: stl_vector.h
*/