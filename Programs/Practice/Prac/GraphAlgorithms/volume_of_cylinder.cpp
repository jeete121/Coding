#include <bits/stdc++.h>
using namespace std;
#define PI 3.14
//function to find the volume
//of the cylinder
double volumeCylinder(double radius,double height)
{
    double volume =PI*radius*radius*height;
    return volume;
}
int main()
{
    double radius=5;
    double height =6;
    double volume =volumeCylinder(radius,height);
    cout<<"Volume of cylinder is ";
    cout<<volume<<"\n";
    return 0;
}