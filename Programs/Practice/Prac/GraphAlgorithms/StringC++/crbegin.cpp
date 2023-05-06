#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    string ::const_reverse_iterator it = str.crbegin();

    cout << *it << "\n";

    return 0;
}
/*
Returns a read-only (constant) reverse iterator that points
to the last character in the %string. Iteration is done in
reverse element order.

File: basic_string.h
*/