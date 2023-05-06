#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abcdefffb";

    cout << str.find_last_of("a") << "\n";
    

    return 0;
}
/*
Find last position of a character of C string.

Parameters:
__s – C string containing characters to locate.
__pos – Index of character to search back from (default end).

Returns:
Index of last occurrence. Starting from __pos, searches backward for
 one of the characters of __s within this string. If found, returns 
 the index where it was found. If not found, returns npos.
*/