#include <bits/stdc++.h>
using namespace std;
//Function to check given
//number is perfect square
bool isPerfectSquare(int n)
{
    int low=1;
    int high=n;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(mid*mid==n)
            return true;
        else if(mid*mid>n)
           high=mid-1;
        else 
           low=mid+1;
    }
   return false;
}
int main()
{
    int n=9;
    if(isPerfectSquare(n))
       cout<<"Number is perfect square\n";
    else
       cout<<"Number is not a perfect square\n";
   return 0;
}
//Time Complexity: O(log(n))
//Space Complexity:O(1)