#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {7, 3, 4, 1, 2, 10};

    vector<int>::iterator it = is_heap_until(arr.begin(), arr.end());

    cout << *it << "\n";

    return 0;
}
/*
Search the end of a heap.

Parameters:
__first – Start of range.
__last – End of range.

Returns:
An iterator pointing to the first element not in the heap.

File: stl_heap.h
*/