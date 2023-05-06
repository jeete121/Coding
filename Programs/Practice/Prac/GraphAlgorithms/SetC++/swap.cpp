#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert({1, 2, 4, 3});

    set<int> st1;
    st1.insert({5, 6, 7, 10, 11});
    st.swap(st1);

    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it << " ";
    cout << "\n";

    for (auto it = st1.begin(); it != st1.end(); it++)
        cout << *it << " ";
   
    return 0;
}
/*
This function swaps values of two sets.
*/