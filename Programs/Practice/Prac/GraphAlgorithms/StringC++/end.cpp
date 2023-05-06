#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abc";

    string ::iterator it = str.end();

    cout << *(it - 1) << "\n";

    return 0;
}
/*
Returns a read/write iterator that points one past the last
character in the %string.
*/