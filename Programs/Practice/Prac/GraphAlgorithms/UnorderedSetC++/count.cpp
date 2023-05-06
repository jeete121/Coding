#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st;
    st.insert(9);
    st.insert(4);

    int x = 4;
    cout << st.count(x) << "\n";

    return 0;
}
/*
std::size_t std::unordered_set<int>::count(const int &__x) const
Finds the number of elements.

Parameters:
__x – Element to located.

Returns:
Number of elements with specified key. 
This function only makes sense for unordered_multisets; 
for unordered_set the result will either be 0 (not present) 
or 1 (present).
*/