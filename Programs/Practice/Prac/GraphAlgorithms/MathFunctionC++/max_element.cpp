#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3, 6, 12, 7, 54, 12, 45};

    vector<int>::iterator it = max_element(arr.begin(), arr.end());

    

    cout << *it << "\n";
}
/*
constexpr std::vector<int>::iterator std::max_element<std::
vector<int>::iterator>(std::vector<int>::iterator, 
std::vector<int>::iterator)
+2 overloads

Return the maximum element in a range.

Parameters:
__first – Start of range.
__last – End of range.

Returns:
Iterator referencing the first instance of the largest value.
*/