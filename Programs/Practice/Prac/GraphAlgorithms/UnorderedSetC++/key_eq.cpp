#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<string> st;

    bool res = st.key_eq()("hello", "hello");
    if (res==1)
        cout << "equal\n";
    else
        cout << "not equal\n";

    return 0;
}
/*
std::equal_to<int> std::unordered_set<int>::key_eq() const

Returns the key comparison object with which the %unordered_set was
constructed.

File: unordered_set.h
*/