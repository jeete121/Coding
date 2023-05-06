#include <bits/stdc++.h>
using namespace std;

int main()
{
    array<int, 4> arr = {3, 5, 6, 7};

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
   
    return 0;
}
/*
A standard container for storing a fixed size sequence of elements.

Template Parameters:
Tp – Type of element. Required to be a complete type.
N – Number of elements.
*/