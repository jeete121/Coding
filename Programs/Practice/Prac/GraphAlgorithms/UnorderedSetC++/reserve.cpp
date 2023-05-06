#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {1, 2, 3, 4};
    int n = 56;

    cout << "Before reserve bucket count is " << st.bucket_count() << "\n";
    st.reserve(n);

    cout << "After reserve bucket count is " << st.bucket_count() << "\n";
    return 0;
}
/*
void std::unordered_set<int>::reserve(std::size_t __n)

Prepare the %unordered_set for a specified number of elements.

Parameters:
__n – Number of elements required. Same as rehash(ceil(n / max_load_factor())).

File: unordered_set.h
*/