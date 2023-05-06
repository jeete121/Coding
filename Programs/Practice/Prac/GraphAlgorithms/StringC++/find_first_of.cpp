#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abcbbabc";

    cout << str.find_first_of("b", 2) << "\n";
    

    return 0;
}
/*
Find position of a character of C string.

Parameters:
__s – String containing characters to locate.
__pos – Index of character to search from (default 0).

Returns:
Index of first occurrence. Starting from __pos, searches 
forward for one of the characters of __s within this string. 
If found, returns the index where it was found. 
If not found, returns npos.
*/