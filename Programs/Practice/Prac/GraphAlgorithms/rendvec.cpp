#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    vector<int>::reverse_iterator it = vec.rend();

    cout << *(it - 1) << "\n";
    
    return 0;
}
/*
Returns a read/write reverse iterator that points to one
before the first element in the %vector. Iteration is done
in reverse element order.

File: stl_vector.h
*/