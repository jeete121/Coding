#include <bits/stdc++.h>
using namespace std;

//function to find the
//kth factor of given number
int kthFactor(int num,int k)
{
    //vector to hold the factor of the given 
    //number
    vector<int> factor;
    
    for(int i=1;i*i<=num;i++)
      {
          //if i divides num
          if(num%i==0)
           {
               //if num/i ==i then push only
               //one into the factor
               if(num/i==i)
                 factor.push_back(i);
            
            //else push both fatcors
               else
               {
                   factor.push_back(i);
                   factor.push_back(num/i);
               }
               
           }
      }
      //sort the factor array
      sort(factor.begin(),factor.end());
     //if factors are less
     //then k then return -1
     if(factor.size()<k)
        return -1;
    //if factors are greater than or
    //equal to k return factor[k-1]
     else
        return factor[k-1];
      
}
int main()
{
    int num=24;
    int k=5;
    int fact=kthFactor(num,k);
    cout<<"Kth factor is ";
    cout<<fact<<"\n";
    return 0;
}