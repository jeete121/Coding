#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";
    string ::const_iterator it = str.cbegin();

    cout << *it << "\n";

    return 0;
}
/*
Returns a read-only (constant) iterator that points to the first
character in the %string.
*/