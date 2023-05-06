#include <bits/stdc++.h>
using namespace std;

//function to find the gcd 
//and the coefficient of
//equation ax+by=gcd(a,b)
int gcd(int a,int b,int &x,int &y)
{
    if(b==0)
      {
          x=1;
          y=0;
          return a;
      }
    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

//function to check if solution 
//exist of the equation
// ax+by=c and find that solution
bool findSolution(int a,int b,int c,int &x0,int &y0,int &g)
{
    g=gcd(abs(a),abs(b),x0,y0);
    if(c%g!=0)
       return false;
    x0=(x0*c)/g;
    y0=(y0*c)/g;
    if(a<0)
       x0=-x0;
    if(b<0)
       y0=-y0;
    return true;
}
int main()
{
    int a=7,b=4,c=2;
    int x,y,g;
    if(findSolution(a,b,c,x,y,g)==false)
       cout<<"No Solution\n";
    else
    {
        cout<<"Solution\n";
        cout<<x<<" "<<y<<"\n";
    }
    return 0;
}
//Time Comlexity: O(log(min(a,b)))