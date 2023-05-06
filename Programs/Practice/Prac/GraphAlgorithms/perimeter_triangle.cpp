#include <bits/stdc++.h>
using namespace std;
//function to find the perimeter of
//triangle
double perimeterTriangle(double a ,double b,double c)
{
    double perimeter=a+b+c;
    return perimeter;
}
int main()
{
    double side1=4;
    double side2=3;
    double side3=5;
    double perimeter=perimeterTriangle(side1,side2,side3);
    cout<<"Perimeter of triange is ";
    cout<<perimeter<<"\n";
    return 0;
}