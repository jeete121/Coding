#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3, 4, 5, 6, 2, 1};

    vector<int>::iterator it = is_sorted_until(arr.begin(), arr.end());

    cout << *it << "\n";

    return 0;
}
/*
Determines the end of a sorted sequence.

Parameters:
__first – An iterator.
__last – Another iterator.

Returns:
An iterator pointing to the last iterator i in [__first, __last) for 
which the range [__first, i) is sorted.

File: stl_algo.h
*/