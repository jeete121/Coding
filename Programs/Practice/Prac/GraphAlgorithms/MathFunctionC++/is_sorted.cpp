#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 4, 6, 8, 10};

    cout << is_sorted(arr.begin(), arr.end()) << "\n";

    return 0;
}
/*
Determines whether the elements of a sequence are sorted.

Parameters:
__first – An iterator.
__last – Another iterator.

Returns:
True if the elements are sorted, false otherwise.

File: stl_algo.h
*/