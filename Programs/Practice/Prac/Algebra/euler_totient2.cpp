#include <bits/stdc++.h>
using namespace std;

//array to store the euler totient value
//or count of coprime of the current number
int phi[1000001];

//function to find the euler
//totient value of number till N
void eulerTotientFomr1ToN(int N)
{

    //initialize the count of
    //coprime as same as i
    //for all number till N
    for(int i=1;i<=N;i++)
       phi[i]=i;

    //iterate tiil the N
    for(int i=2;i<=N;i++)
      {
          //if phi[i] is same sa i 
          //then 
          if(phi[i]==i)
            {
                //then iterate from i to N
                //and incement by i
                //and update for every
                //formula: phi[num]=phi[num]/i*(i-1)
                for(int j=i;j<=N;j+=i)
                  {
                      phi[j]/=i;
                      phi[j]*=(i-1);
                  }
            }
      }
}
int main()
{
    int num=10;
    eulerTotientFomr1ToN(num);
    for(int i=1;i<=num;i++)
       cout<<phi[i]<<" ";
    return 0;
}
//Time Complexity: O(nloglog(n))