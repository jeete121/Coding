#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    cout << str.find_first_not_of("b", 1) << "\n";
    

    return 0;
}
/*
Find position of a character not in C string.

Parameters:
__s – C string containing characters to avoid.
__pos – Index of character to search from (default 0).

Returns:
Index of first occurrence. Starting from __pos, searches 
forward for a character not contained in __s within this string. 
If found, returns the index where it was found. If not found, 
returns npos.
*/