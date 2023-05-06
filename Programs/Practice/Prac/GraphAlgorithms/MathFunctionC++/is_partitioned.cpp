#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4};

    cout << is_partitioned(arr.begin(), arr.end(), [](int i)
                           { return i % 2 == 0; })
         << "\n";
    

        return 0;
}
/*
Checks whether the sequence is partitioned.

Parameters:
__first – An input iterator.
__last – An input iterator.
__pred – A predicate.

Returns:
True if the range [__first,__last) is partioned by __pred, i.e. if all 
elements that satisfy __pred appear before those that do not.

File: stl_algo.h
*/