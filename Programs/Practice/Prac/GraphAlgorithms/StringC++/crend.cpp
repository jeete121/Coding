#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    string ::const_reverse_iterator it = str.crend();

    cout << *(it-1) << "\n";
    

    return 0;
}
/*
Returns a read-only (constant) reverse iterator that points
to one before the first character in the %string. Iteration
is done in reverse element order.
*/