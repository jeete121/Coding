#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {4, 6, 8, 12, 2, 5};

    unordered_set<int>::allocator_type type = st.get_allocator();

    int x = 4;
    cout << "Address is " << type.address(x) << "\n";

    cout << "Maximum size is " << type.max_size() << "\n";

    return 0;
}
/*
std::allocator<int> std::unordered_set<int>::get_allocator() const
Returns the allocator object used by the %unordered_set.

File: unordered_set.h
*/