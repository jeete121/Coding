#include <bits/stdc++.h>
using namespace std;

int subtractProductAndSum(int n) 
{
        int sum = 0;
        int prod = 1;
        while (n != 0) {
            int mod = n % 10;
            sum += mod;
            prod *= mod;
            n /= 10;
        }
        return prod - sum;
}

int main()
{
    int n = 245;
    int sub = subtractProductAndSum(n);
    cout<<sub<<"\n";
    return 0;
}
