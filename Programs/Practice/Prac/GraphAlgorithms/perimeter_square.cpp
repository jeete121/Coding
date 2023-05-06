#include <bits/stdc++.h>
using namespace std;
//function to find the  perimeter
//of the square
double perimeterSquare(double side)
{
    double perimeter=4*side;
    return perimeter;
}
int main()
{
    double side=6;
    double perimeter=perimeterSquare(side);
    cout<<"Perimeter of square is ";
    cout<<perimeter<<"\n";
    return 0;
}