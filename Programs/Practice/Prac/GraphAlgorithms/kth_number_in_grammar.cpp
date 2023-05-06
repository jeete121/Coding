#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int N, int K)
{
     if(N==1&&K==1)
            return 0;
     int mid=pow(2,N-1)/2;
     if(K<=mid)
          return kthGrammar(N-1,K);
     return !kthGrammar(N-1,K-mid);

}

int main()
{
  int n=2,k=2;
  cout<<kthGrammar(n,k);
  return 0;
}