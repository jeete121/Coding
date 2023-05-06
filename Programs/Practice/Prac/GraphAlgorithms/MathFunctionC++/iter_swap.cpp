#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    //swaps first and third
    iter_swap(vec.begin(), vec.begin() + 2);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    return 0;
}
/*
template<class _ForwardIterator1, class _ForwardIterator2> 
void std::iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)

Swaps the contents of two iterators.

Parameters:
__a – An iterator.
__b – Another iterator.

Returns:
Nothing. This function swaps the values pointed to by two iterators,
 not the iterators themselves.

File: stl_algobase.h
*/