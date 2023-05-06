#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "bcabcdef";

    cout << str.find_last_not_of("a") << "\n";
    

    return 0;
}
/*
Find last position of a character not in C string.

Parameters:
__s – C string containing characters to avoid.
__pos – Index of character to search back from (default end).

Returns:
Index of last occurrence. Starting from __pos, searches backward for
 a character not contained in __s within this string. If found, returns 
 the index where it was found. If not found, returns npos.
*/