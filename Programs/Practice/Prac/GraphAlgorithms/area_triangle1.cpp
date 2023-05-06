#include <bits/stdc++.h>
using namespace std;
//function to find area of 
//triangle
double areaTriangle(double  base,double  height)
{
    double  area=(base*height)/2;
    return area;
}
int main()
{
    double  base=13;
    double  height=5;
    double  area=areaTriangle(base,height);
    cout<<"Area of triangle is ";
    cout<<area<<"\n";
    return 0;
}