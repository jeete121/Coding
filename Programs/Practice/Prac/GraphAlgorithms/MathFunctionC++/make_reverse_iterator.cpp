#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    make_reverse_iterator(arr.begin());
    

    return 0;
}
/*
template<class _Iterator> std::reverse_iterator<_Iterator> 
std::make_reverse_iterator(_Iterator __i)

_GLIBCXX_RESOLVE_LIB_DEFECTS
DR 2285. make_reverse_iterator
Generator function for reverse_iterator.

File: stl_iterator.h
*/