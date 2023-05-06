#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 4, 3};

    vector<int> vec = {4, 3, 1};

    cout << is_permutation(arr.begin(), arr.end(), vec.begin()) << "\n";

    return 0;
}
/*
Checks whether a permutation of the second sequence is equal to the first sequence.

Parameters:
__first1 – Start of first range.
__last1 – End of first range.
__first2 – Start of second range.

Returns:
true if there exists a permutation of the elements in the range
 [__first2, __first2 + (__last1 - __first1)), beginning with 
 ForwardIterator2 begin, such that equal(__first1, __last1, begin) 
 returns true; otherwise, returns false.

 File: stl_algo.h
*/