#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 5, 6, 10, 11};

    vector<int>::iterator it = arr.begin();

    //it moves the iterator 2 ponits away from
    //begin so it points to 6
    advance(it, 2);

    cout << *it << "\n";

    return 0;
}
/*
Advances the iterator it by n element positions.

Parameters
it - Iterator to be advanced.
Input  Iterator shall be at least an input iterator.
n- Number of element positions to advance.
This shall only be negative for random-access and bidirectional iterators.
Distance shall be a numerical type able to represent distances between 
iterators of this type.

*/