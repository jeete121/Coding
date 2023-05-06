#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(4);
    st.insert(2);
    st.insert(3);
    st.insert(1);

    cout << st.empty() << "\n";

    return 0;
}
/*
Returns true if the %set is empty.

File: stl_set.h
*/