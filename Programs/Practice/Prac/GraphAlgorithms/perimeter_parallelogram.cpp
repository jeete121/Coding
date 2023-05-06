#include <bits/stdc++.h>
using namespace std;
//function to find the  perimeter
//of the parallelogram
double perimeterParallelogram(double side1,double side2)
{
    double perimeter=2*(side1+side2);
    return perimeter;
}
int main()
{
    //one parallel side
    double side1=4;
    //another paralle side
    double side2=5;
    double perimeter=perimeterParallelogram(side1,side2);
    cout<<"Perimeter of square is ";
    cout<<perimeter<<"\n";
    return 0;
}