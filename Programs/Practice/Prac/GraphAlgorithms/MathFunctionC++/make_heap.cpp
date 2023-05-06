#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3, 2, 1, 4, 5, 10, 6};
    make_heap(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}
/*
Construct a heap over a range.

Parameters:
__first – Start of heap.
__last – End of heap.

File: stl_heap.h
*/