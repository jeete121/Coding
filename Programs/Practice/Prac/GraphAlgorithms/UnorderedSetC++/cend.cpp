#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {9, 4, 10, 12, 45, 2};

    for (int i = 0; i < st.bucket_count(); i++)
    {
        cout << "Bucket " << i << " contains: ";
        for (auto it = st.cbegin(i); it != st.cend(i); it++)
            cout << *it << " ";
        cout << "\n";
    }

    return 0;
}
/*
std::unordered_set<int>::const_iterator std::unordered_set<int>::cend() const

+1 overload

Returns a read-only (constant) iterator that points one past the last
element in the %unordered_set.

File: unordered_set.h
*/