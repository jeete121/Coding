#include <bits/stdc++.h>
using namespace std;


int nthUglyNumber(int n) 
{   
    int ugly[n];
    int i2 = 0, i3 = 0, i5 = 0; 
    int nextValue_2 = 2; 
    int  nextValue_3 = 3; 
    int nextValue_5 = 5; 
    int  next_ugly_no = 1; 
    ugly[0] = 1; 
    for (int i=1; i<n; i++) 
    { 

        //update next ugly number as min of all three
       next_ugly_no = min(nextValue_2, 
                           min(nextValue_3, 
                               nextValue_5)); 
       ugly[i] = next_ugly_no; 

      //update for 2
       if (next_ugly_no == nextValue_2) 
       { 
           i2 = i2+1; 
           nextValue_2 = ugly[i2]*2; 
       } 

      //update for 3
       if (next_ugly_no == nextValue_3) 
       { 
           i3 = i3+1; 
           nextValue_3 = ugly[i3]*3; 
       } 

       //update for 5
       if (next_ugly_no == nextValue_5) 
       { 
           i5 = i5+1; 
           nextValue_5 = ugly[i5]*5; 
       } 
    }
    return next_ugly_no;
        
}
int main()
{
    int n=10;

    cout<<nthUglyNumber(n);
    return 0;

}
