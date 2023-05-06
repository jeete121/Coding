#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    cout << str.rfind('a') << "\n";

    return 0;
}
/*
Find last position of a character.

Parameters:
__c – Character to locate.
__pos – Index of character to search back from (default end).

Returns:
Index of last occurrence. Starting from __pos, 
searches backward for __c within this string. If found, 
returns the index where it was found. If not found, returns npos.
*/