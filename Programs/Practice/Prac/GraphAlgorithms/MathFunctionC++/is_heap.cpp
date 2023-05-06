#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {7, 5, 6, 3, 4, 1, 2};

    cout << is_heap(arr.begin(), arr.end()) << "\n";

    return 0;
}
/*
Determines whether a range is a heap.

Parameters:
__first – Start of range.
__last – End of range.

Returns:
True if range is a heap, false otherwise.
*/