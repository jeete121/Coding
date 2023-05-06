#include <bits/stdc++.h>
using namespace std;
#define PI 3.14
//function to find the
//area of circle
double areaCircle(double radius)
{
    double area=PI*radius*radius;
    return area;
}
int main()
{
    double radius=10;
    double area=areaCircle(radius);
    cout<<"Area of circle is ";
    cout<<area<<"\n";
    return 0;

}