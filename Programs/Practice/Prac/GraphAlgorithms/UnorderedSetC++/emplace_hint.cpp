
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {1, 4, 6, 7};

    int val = 5;
    st.emplace_hint(st.begin(), val);

    cout << "All elements are: ";
    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it << " ";

    return 0;
}
/*

template<class... _Args> std::unordered_set<int>::iterator std::unordered_set<int>::emplace_hint(std::unordered_set<int>::const_iterator __pos, _Args &&...__args)
Attempts to insert an element into the %unordered_set.

Parameters:
__pos – An iterator that serves as a hint as to where the element should be inserted.
__args – Arguments used to generate the element to be inserted.

Returns:
An iterator that points to the element with key equivalent to the one generated from __args (may or may not be the element itself). This function is not concerned about whether the insertion took place, and thus does not return a boolean like the single-argument emplace() does. Note that the first parameter is only a hint and can potentially improve the performance of the insertion process. A bad hint would cause no gains in efficiency. For more on hinting, see: https://gcc.gnu.org/onlinedocs/libstdc++/manual/associative.html#containers.associative.insert_hints Insertion requires amortized constant time.

File: unordered_set.h
*/