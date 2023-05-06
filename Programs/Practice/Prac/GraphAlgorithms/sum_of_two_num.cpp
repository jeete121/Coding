#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b)
{

    //base case
    if (a == 0)
        return b;

    //base case
    if (b == 0)
        return a;
    int sum = a ^ b;
    int carry = (unsigned int)(a & b) << 1;
    return getSum(sum, carry);
}

int main()
{
    int a = 1, b = 2;
    cout << getSum(a, b);
    return 0;
}