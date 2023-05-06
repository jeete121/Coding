#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str = "abc";

    cout << str.data() << "\n";

    return 0;
}
/*
Return const pointer to contents. This is a pointer to internal 
data. It is undefined to modify the contents through the
 returned pointer. To get a pointer that allows modifying 
 the contents use &str[0] instead, (or in C++17 the non-const
  str.data() overload).
*/