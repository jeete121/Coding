#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b,int &x,int &y)
{
    if(a==0)
      {
          x=0;
          y=1;
          return b;
      }
     int x1,y1;
     int d=gcd(b%a,a,x1,y1);
     x=y1-(b/a)*x1;
     y=x1;
     return d;
}
bool find_any_solution(int a,int b,int c,int &x0,int &y0,int &g)
{
    g=gcd(abs(a),abs(b),x0,y0);
    if(c%g)
       return false;
    x0=x0*(c/g);
    y0=y0*(c/g);
    if(a<0)
      x0=-x0;
    if(b<0)
      y0=-y0;
    return true;
}
int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   int x0,y0,g;
   if(find_any_solution(a,b,c,x0,y0,g))
     {
         cout<<"Solution is :\n";
         cout<<"x is : "<<x0<<"\n";
         cout<<"y is : "<<y0<<"\n";
     }
    else
       cout<<"No solution \n";
   return 0;
    
}