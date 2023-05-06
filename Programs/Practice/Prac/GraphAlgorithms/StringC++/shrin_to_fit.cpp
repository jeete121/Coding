//Not Done
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str(10, 'a');

    cout << "Size : " << str.size() << " Capacity: " << str.capacity() << "\n";

    str.shrink_to_fit();

    cout << "Size : " << str.size() << " Capacity: " << str.capacity() << "\n";
  
    return 0;
}
/*
A non-binding request to reduce capacity() to size().

File: basic_string.h
*/