
#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> ms = {1, 2, 3, 4, 1};

    ms.clear();

    for (auto it = ms.begin(); it != ms.end(); it++)
        cout << *it << " ";
}
/*
void std::multiset<int>::clear()

Erases all elements in a %multiset. Note that this function only
erases the elements, and that if the elements themselves are pointers,
the pointed-to memory is not touched in any way. Managing the pointer
is the user's responsibility.

File: stl_multiset.h
*/