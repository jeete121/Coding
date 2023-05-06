#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {5, 34, 3, 12, 4, 21};

    vector<int>::iterator it = min_element(arr.begin(), arr.end());

    cout << *it << "\n";

    return 0;
}
/*

template<class _FIter> constexpr _FIter 
std::min_element(_FIter __first, _FIter __last)

+1 overload
Return the minimum element in a range.

Parameters:
__first – Start of range.
__last – End of range.

Returns:
Iterator referencing the first instance of the smallest value.

File: stl_algo.h
*/