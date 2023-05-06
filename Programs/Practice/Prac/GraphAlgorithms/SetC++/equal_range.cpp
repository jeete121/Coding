#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> st;
    st.insert(4);
    st.insert(2);
    st.insert(3);
    st.insert(1);

    pair<set<int>::iterator, set<int>::iterator> p = st.equal_range(3);

    cout << *p.first << " " << *p.second << "\n";

    return 0;
}
/*
Finds a subsequence matching given key.

Parameters:
__x – Key to be located.

Returns:
Pair of iterators that possibly points to the subsequence matching given
 key. This function is equivalent to std::make_pair(c.lower_bound(val),
  c.upper_bound(val)) (but is faster than making the calls separately).
   This function probably only makes sense for multisets.
*/