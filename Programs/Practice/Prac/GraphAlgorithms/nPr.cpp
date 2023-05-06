#include <bits/stdc++.h>
using namespace std;

//function to find the factorial
//of given number
 int factorialR(int num) 
 {
    //base case
    if (num == 1)
        return num;
    return num * factorialR(num - 1);
}
//function to  calculate the nPr
int nPr(int n, int r) 
{
    // formula: fact(n) / fact (n-r)
    return factorialR(n) / factorialR(n - r);
}

int main()
{
    int n = 5;
    int r = 2;
    int npr = nPr(n, r);
    cout<<npr<<"\n";
    return 0;
}
