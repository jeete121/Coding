#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {3, 12, 45, 3, 10};

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
std::unordered_set<int>::iterator std::unordered_set<int>::end()

+2 overloads

Returns a read-only (constant) iterator that points one past the last
element in the %unordered_set.

File: unordered_set.h
*/