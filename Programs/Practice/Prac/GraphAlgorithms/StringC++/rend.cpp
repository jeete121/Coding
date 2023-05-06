#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    string ::reverse_iterator it = str.rend();

    cout << *(it - 1) << "\n";

    return 0;
}
/*
Returns a read/write reverse iterator that points to one before the
first character in the %string. Iteration is done in reverse
element order.

File: basic_string.h
*/