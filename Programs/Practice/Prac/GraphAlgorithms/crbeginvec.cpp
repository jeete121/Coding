#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};

    vector<int>::const_reverse_iterator it = vec.crbegin();
    cout << *it << "\n";

    return 0;
}
/*
Returns a read-only (constant) reverse iterator that points
to the last element in the %vector. Iteration is done in
reverse element order.

File: stl_vector.h
*/