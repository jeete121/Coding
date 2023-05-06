#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> ms = {1, 2, 3, 4, 1};

    multiset<int>::iterator it = ms.cend();

    cout << *it << "\n";
}
/*
std::multiset<int>::iterator std::multiset<int>::cend() const

Returns a read-only (constant) iterator that points one past the last
element in the %multiset. Iteration is done in ascending order
according to the keys.

File: stl_multiset.h
*/