#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st;
    st.insert(9);
    st.insert(4);

    st.clear();

    cout << st.size() << "\n";

    return 0;
}
/*
void std::unordered_set<int>::clear()

Erases all elements in an %unordered_set. Note that this function only
erases the elements, and that if the elements themselves are pointers,
the pointed-to memory is not touched in any way. Managing the pointer
is the user's responsibility.

File: unordered_set.h
*/