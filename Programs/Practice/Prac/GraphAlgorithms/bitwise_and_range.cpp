#include <bits/stdc++.h>
using namespace std;

//function to find the 
//MSB position of the number
int MSB(int n)
{
    int pos=-1;
    while(n)
        {
            n=n>>1;
            pos++;
        }
        return  pos;
}

//function to find the bitwise and of
//range from m to n
int rangeBitwiseAnd(int m, int n) 
{
   int res=0;
    while(m&&n) 
    {
        int pos1=MSB(m);
        int pos2=MSB(n);

        //if MSB of both are not same then break
        //because and of the range will be zero
        if(pos1!=pos2)
             break;
         //else update the result
         res+=1<<pos1;

        //subtract MSB from both the number
        m-=1<<pos1;
        n-=1<<pos1;
      }
    //return the final answer    
    return res;      
}
int main()
{
    int a=5;
    int b=7;
    cout<<rangeBitwiseAnd(a,b);
    return 0;
}
