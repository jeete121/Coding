#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    string ::const_iterator it = str.cend();

    cout << *(it - 1) << "\n";

    return 0;
}
/*
Returns a read-only (constant) iterator that points one past the
last character in the %string.

File: basic_string.h
*/