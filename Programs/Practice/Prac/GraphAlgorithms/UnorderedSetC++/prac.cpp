#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st;
    st.insert(9);
    st.insert(4);

    unordered_set<int> st1;
    st1.insert(10);
    st1.insert(45);
    st1.insert(123);

    st.swap(st1);
    cout << st.size() << "\n";
    return 0;
}
/*
void std::unordered_set<int>::swap(std::unordered_set<int> &__x)

Swaps data with another %unordered_set.

Parameters:
__x – An %unordered_set of the same element and allocator types. This exchanges the elements between two sets in constant time. Note that the global std::swap() function is specialized such that std::swap(s1,s2) will feed to this function.

File: unordered_set.h
*/