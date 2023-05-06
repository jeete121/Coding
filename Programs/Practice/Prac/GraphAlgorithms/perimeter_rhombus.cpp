#include <bits/stdc++.h>
using namespace std;
//function to find the perimeter
//of rhombus
double perimeterRhombus(double side)
{
    double perimeter=4*side;
    return perimeter;
}
int main()
{
    double side=8;
    double perimeter=perimeterRhombus(side);
    cout<<"Perimeter of rhombus is ";
    cout<<perimeter<<"\n";
    return 0;
}