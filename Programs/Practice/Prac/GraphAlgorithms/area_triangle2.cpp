#include <bits/stdc++.h>
using namespace std;
//function to find area of 
//triangle
double areaTriangle(double  side1,double  side2,double side3)
{
    double  s=(side1+side2+side3)/2;
    double area=sqrt(s*(s-side1)*(s-side2)*(s-side3));
    return area;
}
int main()
{
    double  side1=3;
    double  side2=4;
    double side3=5;
    double  area=areaTriangle(side1,side2,side3);
    cout<<"Area of triangle is ";
    cout<<area<<"\n";
    return 0;
}