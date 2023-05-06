#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b,long long int &x,long long int &y)
{
    if(b==0)
      {
          x=1;
          y=0;
          return a;
      }
      long long int x1,y1;
      long long int d=gcd(b,a%b,x1,y1);
      x=y1;
      y=x1-y1*(a/b);
      return d;
}
bool find_any_solution(long long int a,long long int b,long long int c,long long int &x0,long long int &y0,long long int &g)
{
    g=gcd(abs(a),abs(b),x0,y0);
    if(c%g)
       return false;
    x0=x0*c/g;
    y0=y0*c/g;
    if(a<0)
       x0=-x0;
    if(b<0)
       y0=-y0;
    return true;
    
}
void shift_solution(long long int & x, long long int & y, long long int a, long long int b, long long int cnt)
 {
    x += cnt * b;
    y -= cnt * a;
}
long long int find_all_solutions(long long int a, long long int b, long long int c, long long int minx, long long int maxx, long long int miny, long long int maxy)
{
    long long int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    long long int sign_a = a > 0 ? +1 : -1;
    long long int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    long long int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    long long int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    long long int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    long long int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    long long int lx = max(lx1, lx2);
    long long int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
int main()
{
    long long int a,b,c;
    cin>>a>>b>>c;
    if(c<0)
      c=-c;
    long long int x1,x2,y1,y2;
    cin>>x1>>x2;
    cin>>y1>>y2;
    long long int ans=find_all_solutions(a,b,c,x1,x2,y1,y2);
    cout<<ans<<"\n";
}