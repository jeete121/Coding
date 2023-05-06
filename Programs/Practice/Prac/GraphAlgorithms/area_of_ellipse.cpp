#include <bits/stdc++.h>
using namespace std;
#define PI 3.14
//function to find the area of
//ellipse
double areaEllipse(double minor_axis,double major_axis)
{
    double  area=PI*(minor_axis/2)*(major_axis/2);
    return area;
}
int main()
{
    double minor_axis=10;
    double major_axis=16;
    double area=areaEllipse(minor_axis,major_axis);
    cout<<"Area of Ellipse is ";
    cout<<area<<"\n";
    return 0;
}