#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {1, 2, 3, 4, 5, 6, 89, 12};

    cout << st.load_factor() << "\n";
    return 0;
}
/*
float std::unordered_set<int>::load_factor() const

Returns the average number of elements per bucket.

File: unordered_set.h
*/