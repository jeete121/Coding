#include <bits/stdc++.h>
using namespace std;

//function to find the
// factorial of a given number
int factorialR(int num) 
{
   //base case
   if (num == 1)
        return num;
     return num * factorialR(num - 1);
}

//function to  calculate the nCr
int nCr(int n, int r) 
 {
    // formula: fact(n) / (fact(r)*fact (n-r))
    int nfact = factorialR(n);
    int rfact = factorialR(r);
    int rnfact = factorialR(n - r);
    return nfact / (rfact * rnfact);
}
int main()
{
    int n = 5;
    int r = 2;
    int ncr = nCr(n, r);
    cout<<ncr<<"\n";
    return 0;
}

