#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 4, 7, 9, 1, 6, 9, 10};
    vector<int> arr(vec.size());

    adjacent_difference(vec.begin(), vec.end(), arr.begin());

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}
/*


Return differences between adjacent values. Computes the difference 
between adjacent values in the range [first,last) using operator-() 
and writes the result to __result.

Parameters:
__first – Start of input range.
__last – End of input range.
__result – Output sums.

Returns:
Iterator pointing just beyond the values written to result. 
_GLIBCXX_RESOLVE_LIB_DEFECTS DR 539. partial_sum and 
adjacent_difference should mention requirements

File: stl_numeric.h
*/