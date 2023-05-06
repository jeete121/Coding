#include <bits/stdc++.h>
using namespace std;
#define PI 3.14
//function to find the area
//of sector
double areaSector(double angle,double radius)
{
    double area=PI*(angle)*radius*radius;
    return area;
}
int main()
{
    //angle value in radian
    double angle=0.166;
    double radius=5;
    double  area=areaSector(angle,radius);
    cout<<"Area of sector is ";
    cout<<area<<"\n";
    return 0;
}