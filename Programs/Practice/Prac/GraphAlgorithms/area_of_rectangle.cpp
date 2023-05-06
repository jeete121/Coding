#include <bits/stdc++.h>
using namespace std;
//function to find the area of
//rectangle
double areaRectangle(double length,double width)
{
    return length*width;
}
int main()
{
    double length=3;
    double width=4;
    double area=areaRectangle(length,width);
    cout<<"Area of rectangle is ";
    cout<<area<<"\n";
    return 0;
}