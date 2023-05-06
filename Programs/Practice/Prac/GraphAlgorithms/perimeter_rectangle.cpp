#include <bits/stdc++.h>
using namespace std;
//function to find the  perimeter
//of the rectangle
double perimeterRectangle(double side1,double side2)
{
    double perimeter=2*(side1+side2);
    return perimeter;
}
int main()
{
    double side1=4;
    double side2=3;
    double perimeter=perimeterRectangle(side1,side2);
    cout<<"Perimeter of square is ";
    cout<<perimeter<<"\n";
    return 0;
}