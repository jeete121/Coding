#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st;
    st.insert(9);
    st.insert(4);

    int n = 2;

    cout << st.bucket_size(n) << "\n";

    return 0;
}
/*
std::size_t std::unordered_set<int>::bucket_size(std::size_t __n) const

Returns the number of elements in a given bucket.

Parameters:
__n – A bucket index.

Returns:
The number of elements in the bucket.

File: unordered_set.h
*/