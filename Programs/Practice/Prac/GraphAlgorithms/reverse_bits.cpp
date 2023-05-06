#include <bits/stdc++.h>
using namespace std;


//function to reverse bits
//of 32 bit number
unsigned int  reverseBits(unsigned int n)
 {
       unsigned int x= 0;
        for(int i = 31; i>=0;i-- ) 
        {
            x |= (n & 1) << i;
            n =n>>1;
        }
        return x;
}
int main()
{
  unsigned  int n = 43261596;
  unsigned  int x =reverseBits(n);
  cout<<x<<"\n";
  return 0;
}
