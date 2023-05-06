#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;

    st = {3, 2, 1, 4};

    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it << " ";

    return 0;
}
/*
%Set list assignment operator.

Parameters:
__l – An initializer_list. This function fills a %set with copies
 of the elements in the initializer list __l. Note that the assignment
  completely changes the %set and that the resulting %set's size is
   the same as the number of elements assigned.
*/