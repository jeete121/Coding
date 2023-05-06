#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {1, 2, 3, 4, 5};

    cout << st.max_size() << "\n";
    return 0;
}
/*
std::size_t std::unordered_set<int>::max_size() const

Returns the maximum size of the %unordered_set.

File: unordered_set.h
*/