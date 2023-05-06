#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {1, 2, 3, 4, 10, 23, 45};

    // cout << st.max_load_factor() << "\n";
    float z = 0.45;
    st.max_load_factor(z);

    cout << "New load factor: " << st.max_load_factor() << "\n";
    return 0;
}
/*
float std::unordered_set<int>::max_load_factor() const
+1 overload

Returns a positive number that the %unordered_set tries to keep the
load factor less than or equal to.
File: unordered_set.h
*/


/*
void std::unordered_set<int>::max_load_factor(float __z)
+1 overload

Change the %unordered_set maximum load factor.

Parameters:
__z – The new maximum load factor.
*/