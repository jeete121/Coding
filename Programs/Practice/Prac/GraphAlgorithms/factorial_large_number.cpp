#include <bits/stdc++.h>
using namespace std;

//define the maximum
//number of digits
//that the factorail holds

#define MAX 10000
//function to numtiply the cuurent
//and update the result array
//and find the new size of the
//fatorial number
int factorial(int x, int fact[], int size1)
{
    int carry = 0;
    //iterate till the end of size
    for (int i = 0; i < size1; i++)
    {
        int prod = fact[i] * x + carry;
        fact[i] = prod % 10;
        carry = prod / 10;
    }

    //while carry>0 increment the size
    while (carry)
    {
        fact[size1] = carry % 10;
        carry = carry / 10;
        size1++;
    }

    //return the new size
    return size1;
}

//function to find the factorial of a number
void factorial(int n)
{
    int fact[MAX];

    fact[0] = 1;
    int size1 = 1;

    for (int x = 2; x <= n; x++)
    {
        size1 = factorial(x, fact, size1);
    }
    for (int i = size1 - 1; i >= 0; i--)
        cout << fact[i];
}

int main()
{
    int n = 25;
    factorial(n);
    return 0;
}