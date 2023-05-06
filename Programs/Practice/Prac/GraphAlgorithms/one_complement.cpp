#include <bits/stdc++.h>
using namespace std;

//function to find the 
//one's complement of a number
int oneComplement(int num)
{
    int n=num;

    int length=0;

    //find the no of bits 
    //in binary form a number
    while(n>0)
      {
          length++;
          n=n/2;
      }
    
   int power=pow(2,length)-1;

   //formaula = (pow(2,lenght)-1)^num
   int complement=power^num;

   //return one's complement
   return complement;
}
int main()
{
    //inout number
    int num=8;

    int complement=oneComplement(num);
    cout<<"One's Complement is ";
    cout<<complement<<"\n";
    return 0;
}