#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st1 = {9, 4, 5};

    unordered_set<int> st2 = {10, 25, 124, 67};

    cout << "unordered_set 1 size before swap :" << st1.size() << "\n";
    cout << "unordered_set 2 size before swap :" << st2.size() << "\n";

    st1.swap(st2);

    cout << "\n";

    cout << "unordered_set 1 size after swap :" << st1.size() << "\n";
    cout << "unordered_set 2 size after swap :" << st2.size() << "\n";
    return 0;
}
/*
void std::unordered_set<int>::swap(std::unordered_set<int> &__x)

Swaps data with another %unordered_set.

Parameters:
__x – An %unordered_set of the same element and allocator types. This exchanges the elements between two sets in constant time. Note that the global std::swap() function is specialized such that std::swap(s1,s2) will feed to this function.

File: unordered_set.h
*/