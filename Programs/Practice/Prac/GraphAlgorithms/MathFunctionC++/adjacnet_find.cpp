#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3, 4, 5, 1, 1, 10};

    vector<int>::iterator it = adjacent_find(arr.begin(), arr.end());
  
    cout << *it << "\n";
    return 0;
}
/*
+1 overload

Find two adjacent values in a sequence that are equal.

Parameters:
__first – A forward iterator.
__last – A forward iterator.

Returns:
The first iterator i such that i and i+1 are both valid iterators in
 [__first,__last) and such that *i == *(i+1), or __last if no such
  iterator exists.
File: stl_algo.h
*/