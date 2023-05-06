#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<string> st = {"Hello", "C++", "Program", "World", "Code"};

    unordered_set<string>::hasher hash = st.hash_function();

    cout << hash("Hello") << "\n";

    cout << hash("C++") << "\n";

    return 0;
}
/*
std::hash<int> std::unordered_set<int>::hash_function() const

Returns the hash functor object with which the %unordered_set was
constructed.

File: unordered_set.h

*/