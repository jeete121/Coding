#include <bits/stdc++.h>
using namespace std;

int main()
{
    intmax_t numer = 10, denom = 3;

    imaxdiv_t res = imaxdiv(numer, denom);

    cout << "quot = " << res.quot << " rem = " << res.rem << "\n";

    return 0;
}
/*
imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom)

File: inttypes.h

Computes the quotient and the remainder of two 
integer values of any size as a single operation.

Parameters
numer
The numerator.

denom
The denominator.

Return Value
imaxdiv called with arguments of type intmax_t returns a structure of 
type imaxdiv_t that comprises the quotient and the remainder.
*/