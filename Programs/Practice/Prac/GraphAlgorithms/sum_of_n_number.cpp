#include <bits/stdc++.h>
using namespace std;
//function to find the
//sum of n natural number
int sumOfNauralnumber(int n)
{
    int sum=n*(n+1)/2;
    return sum;
}
int main()
{
    int n=100;
    int sum=sumOfNauralnumber(n);
    cout<<"Sum of n natural number is ";
    cout<<sum<<"\n";
    return 0;
}