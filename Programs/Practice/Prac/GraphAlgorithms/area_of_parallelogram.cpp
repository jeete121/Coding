#include <bits/stdc++.h>
using namespace std;
//function to find area of
//parallelogram
double areaParallelogram(double base,double height)
{
    double area=base*height;
    return area;
}
int main()
{
    double base=12;
    double height=5;
    double area=areaParallelogram(base,height);
    cout<<"Area of parallelogram is ";
    cout<<area<<"\n";
    return 0;
}