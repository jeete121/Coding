#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    vector<int> vec = {2, 3, 5};

    cout << includes(arr.begin(), arr.end(), vec.begin(), vec.end()) << "\n";

    return 0;
}
/*
bool includes<_IIter1, _IIter2>(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2)

Parameters:
__first1 – Start of search range.
__last1 – End of search range.
__first2 – Start of sequence
__last2 – End of sequence.

Returns:
True if each element in [__first2,__last2) is contained in order 
within [__first1,__last1). False otherwe
Determines whether all elements of a sequence exists in a range.
File: stl_algo.h
*/