#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 10};
    vector<int> vec = {4, 5, 6, 45, 10};

    cout << inner_product(arr.begin(), arr.end(), vec.begin(), 0) << "\n";

    return 0;
}
/*
Compute inner product of two ranges. Starting with an initial value of
 __init, multiplies successive elements from the two ranges and adds 
 each product into the accumulated value using operator+(). 
 The values in the ranges are processed in order.

Parameters:
__first1 – Start of range 1.
__last1 – End of range 1.
__first2 – Start of range 2.
__init – Starting value to add other values to.

Returns:
The final inner product.

File: stl_numeric.h
*/