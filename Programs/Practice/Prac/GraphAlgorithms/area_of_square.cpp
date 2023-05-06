#include <bits/stdc++.h>
using namespace std;
//function to find the
//area of square
double areaSquare(double side)
{
    //area=a*a
    return side*side;
}
int main()
{
    double side=4.5;
    double area=areaSquare(side);
    cout<<"Area of square is ";
    cout<<area<<"\n";
    return 0;
}