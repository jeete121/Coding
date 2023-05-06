#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st;
    st.insert(9);
    st.insert(4);

    cout << st.bucket_count() << "\n";

    return 0;
}
/*
std::size_t std::unordered_set<int>::bucket_count() const

Returns the number of buckets of the %unordered_set.

File: unordered_set.h
*/