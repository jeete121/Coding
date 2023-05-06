#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    str.insert(str.end(), 'd');

    cout << str << "\n";
    
    return 0;
}
/*
Insert one character.

Parameters:
__p – Iterator referencing position in string to insert at.
__c – The character to insert.

Returns:
Iterator referencing newly inserted char.
*/