#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {9, 4, 10, 12, 3, 4, 15};

    for (int i = 0; i < st.bucket_count(); i++)
    {
        cout << "Bucket " << i << " contains: ";
        for (auto it = st.begin(i); it != st.end(i); it++)
            cout << *it << " ";

        cout << "\n";
    }

    return 0;
}
/*
std::unordered_set<int>::iterator std::unordered_set<int>::begin()

+2 overloads

Returns a read-only (constant) iterator that points to the first
element in the %unordered_set.

File: unordered_set.h
*/