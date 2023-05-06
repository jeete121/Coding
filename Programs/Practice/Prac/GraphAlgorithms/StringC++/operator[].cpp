#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    cout << str[0] << "\n";

    return 0;
}
/*
Subscript access to the data contained in the %string.


Parameters:
__pos – The index of the character to access.

Returns:
Read/write reference to the character. This operator allows for 
easy, array-style, data access. Note that data access with this 
operator is unchecked and out_of_range lookups are not defined. 
(For checked lookups see at().)
File: basic_string.h
*/