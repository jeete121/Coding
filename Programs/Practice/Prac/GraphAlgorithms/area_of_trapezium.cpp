#include <bits/stdc++.h>
using namespace std;
//function to find the area
//of trapezium
double areaTrapezium(double parallelside1,double parallelside2,double height)
{
    double area=((parallelside1+parallelside2)*height)/2;
    return area;
}
int main()
{
    double parallelside1=4;
    double parallelside2=5;
    double height=3;
    double area=areaTrapezium(parallelside1,parallelside2,height);
    cout<<"Area of Trapezium is ";
    cout<<area<<"\n";
    return 0;
}