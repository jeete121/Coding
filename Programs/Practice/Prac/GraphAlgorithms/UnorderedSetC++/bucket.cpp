#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st;
    st.insert(9);
    st.insert(4);

    int key = 4;

    cout << st.bucket(key) << "\n";

    return 0;
}
/*
std::size_t std::unordered_set<int>::bucket(const int &__key) const

Returns the bucket index of a given element.

Parameters:
__key – A key instance.

Returns:
The key bucket index.

*/