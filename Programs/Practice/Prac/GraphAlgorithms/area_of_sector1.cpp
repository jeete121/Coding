#include <bits/stdc++.h>
using namespace std;
#define PI 3.14
//function to find the area
//of sector
double areaSector(double angle,double radius)
{
    double area=PI*(angle/360)*radius*radius;
    return area;
}
int main()
{
    //angle value in degree
    double angle=60;
    double radius=5;
    double  area=areaSector(angle,radius);
    cout<<"Area of sector is ";
    cout<<area<<"\n";
    return 0;
}