#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};

    vec.pop_back();

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
        

    return 0;
}
/*
Removes last element. This is a typical stack operation. 
It shrinks the %vector by one. Note that no data is returned,
 and if the last element's data is needed,
 it should be retrieved before pop_back() is called.
*/