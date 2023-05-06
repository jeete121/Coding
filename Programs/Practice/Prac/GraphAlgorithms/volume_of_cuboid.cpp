#include <bits/stdc++.h>
using namespace std;
//function to find the volume of
//cuboid
double volumeCuboid(double length,double width,double height)
{
    double volume=length*width*height;
    return volume;
}
int main()
{
    double length=5;
    double width=3;
    double height=4;
    double volume=volumeCuboid(length,width,height);
    cout<<"Volume of cuboid is ";
    cout<<volume<<"\n";
    return 0;
}