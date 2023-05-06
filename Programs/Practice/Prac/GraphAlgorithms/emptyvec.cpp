#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    if (vec.empty())
        cout << "Vector is empty\n";
    else
        cout << "Vector is not empty\n";
    return 0;
}

/*
Returns true if the %vector is empty. (Thus begin() would
equal end().)
*/