#include <bits/stdc++.h>
using namespace std;

//function to check if two numbers
//are of same sign or not
bool isOppositeSign(int num1, int num2)
{
    if ((num1 ^ num2) < 0)
        return true;
    return false;
}
int main()
{
    int num1 = -10, num2 = 5;

    if (isOppositeSign(num1, num2))
    {
        cout << "Opposite Sign\n";
    }
    else
        cout << "Same Sign\n";

    return 0;
}