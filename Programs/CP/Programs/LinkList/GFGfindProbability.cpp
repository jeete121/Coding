/*
 Given a rectangular matrix where we have equal
 probability of moving in each direction,given 
 starting vertex (i,j) find probablity that in 
 next n moves we never cross the matrix boundaries.
*/
#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x,int y,int m ,int n)
{
    if(x>=0&&x<m &&y>=0&&y<n)
       return true;
    return false;
}
double findProbability(int m,int n,int x,int y,int N)
{
    if(!isSafe(x,y,m,n))
       return 0.0;
    if(N==0)
       return 1.0;
    double prob=0.0;
    prob+=findProbability(m,n,x-1,y,N-1)*0.25;
    prob+=findProbability(m,n,x,y+1,N-1)*0.25;
    prob+=findProbability(m,n,x+1,y,N-1)*0.25;
    prob+=findProbability(m,n,x,y-1,N-1)*0.25;
    return prob;
}
int main()
{
  int m,n,x,y,N;
  cin>>m>>n>>x>>y>>N;
  double res=findProbability(m,n,x,y,N);
  cout<<res<<"\n";
  return 0;
}