#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> vec = {1, 2, 3, 4, 5};

    vector<int>::iterator it = vec.end();

    cout << *(it - 1) << "\n";

    return 0;
}
/*
Returns a read/write iterator that points one past the last
element in the %vector. Iteration is done in ordinary
element order.

File: stl_vector.h
*/