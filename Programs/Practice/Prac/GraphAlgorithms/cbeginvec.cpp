
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 3, 4, 5};
    vector<int>::const_iterator it = vec.cbegin();

    cout << *it << "\n";

    return 0;
}

/*
Returns a read-only (constant) iterator that points to the
first element in the %vector. Iteration is done in ordinary
element order.

File: stl_vector.h
 */