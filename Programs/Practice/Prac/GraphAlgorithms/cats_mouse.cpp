#include <bits/stdc++.h>
using namespace std;
string catAndMouse(int x, int y, int z)
{
    if (abs(x - z) == abs(y - z))
        return "Mouse C";
    else if (abs(x - z) > abs(y - z))
        return "Cat B";
    return "Cat A";
}
int main()
{
    int q = 1;
    int x = 1, y = 3, z = 2;
    cout << catAndMouse(x, y, z);
    return 0;
}
