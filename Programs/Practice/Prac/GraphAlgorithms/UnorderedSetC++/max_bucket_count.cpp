#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {1, 2, 3, 4, 5, 67, 89};

    cout << st.max_bucket_count() << "\n";
    return 0;
}
/*
std::size_t std::unordered_set<int>::max_bucket_count() const

Returns the maximum number of buckets of the %unordered_set.

File: unordered_set.h
*/