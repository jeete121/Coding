#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    make_move_iterator(arr.begin());

    return 0;
}
/*
template<class _Iterator> std::move_iterator<_Iterator> 
std::make_move_iterator(_Iterator __i)

File: stl_iterator.h
*/