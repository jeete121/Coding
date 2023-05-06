#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    string ::reverse_iterator it = str.rbegin();
   
    cout << *it << "\n";
    return 0;
}
/*
Returns a read/write reverse iterator that points to the last
character in the %string. Iteration is done in reverse element
order.

File: basic_string.h
*/