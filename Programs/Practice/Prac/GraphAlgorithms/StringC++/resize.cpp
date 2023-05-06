#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    str.resize(10);

    cout << str.size() << "\n";

    return 0;
}
/*
Resizes the %string to the specified number of characters.

Parameters:
__n – Number of characters the %string should contain. 
This function will resize the %string to the specified length. 
If the new size is smaller than the %string's current size the
 %string is truncated, otherwise the %string is extended and new 
 characters are default-constructed. For basic types such as char, 
 this means setting them to 0.
*/