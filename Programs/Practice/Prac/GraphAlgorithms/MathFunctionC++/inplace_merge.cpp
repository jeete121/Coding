#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 6, 14, 15};
    vector<int> vec = {7, 8, 10, 11};

    sort(arr.begin(), arr.end());
    sort(vec.begin(), vec.end());
    vector<int> res(arr.size() + vec.size());

    vector<int>::iterator it = copy(arr.begin(), arr.end(), res.begin());
    copy(vec.begin(), vec.end(), it);
    inplace_merge(res.begin(), res.begin() + arr.size(), res.end());

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}
/*
Merges two sorted ranges in place.

Parameters:
__first – An iterator.
__middle – Another iterator.
__last – Another iterator.

Returns:
Nothing. Merges two sorted and consecutive ranges, [__first,__middle)
 and [__middle,__last), and puts the result in [__first,__last). 
 The output will be sorted. The sort is stable, that is, for equivalent
  elements in the two ranges, elements
*/