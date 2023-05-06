#include <bits/stdc++.h>
using namespace std;

int main()
{

    pair<int, int> p = minmax({3, 23, 2, 45, 25});

    cout << p.first << " " << p.second << "\n";

    return 0;
}
/*
template<class _Tp> constexpr std::pair<const _Tp &, const _Tp &> 
std::minmax(const _Tp &__a, const _Tp &__b)

+3 overloads

Determines min and max at once as an ordered pair.

File: stl_algo.h
*/