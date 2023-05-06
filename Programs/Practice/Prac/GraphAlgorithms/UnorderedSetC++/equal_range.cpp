#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {9, 4, 5, 4, 6};

    int x = 100;

    auto it = st.equal_range(x);
    if (it.first != it.second)
    {
        for (; it.first != it.second; ++it.first)
            cout << *it.first << " ";
    }
    else
        cout << "Element " << x << " not present in set";

    return 0;
}
/*
std::pair<std::unordered_set<int>::iterator,
 std::unordered_set<int>::iterator> 
 std::unordered_set<int>::equal_range(const int &__x)

+1 overload

Finds a subsequence matching given key.
Returns:
Pair of iterators that possibly points to the subsequence matching given key. This function probably only makes sense for multisets.

File: unordered_set.h
*/