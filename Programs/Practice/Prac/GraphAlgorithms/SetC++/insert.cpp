#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;

    st.insert({1, 4, 5, 6, 1, 2});

    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it << " ";

    return 0;
}
/*
Attempts to insert a list of elements into the %set.

Parameters:
__l – A std::initializer_list<value_type> of elements to be inserted.
 Complexity similar to that of the range constructor.
*/