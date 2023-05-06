#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {1, 2, 3, 4, 5};

    int n = 56;

    cout << "Before rehash bucket count is " << st.bucket_count() << "\n";
    st.rehash(n);

    cout << "After rehash bucket count is " << st.bucket_count() << "\n";
    return 0;
}
/*
void std::unordered_set<int>::rehash(std::size_t __n)

May rehash the %unordered_set.

Parameters:
__n – The new number of buckets. Rehash will occur only if the new number of buckets respect the %unordered_set maximum load factor.

File: unordered_set.h
*/