#include <bits/stdc++.h>
using namespace std;
#define PI 3.14
//function to find the volume
//of sphere
double volumeSphere(double radius)
{
    double volume=PI*(4/3)*radius*radius*radius;
    return volume;
}
int main()
{
    double radius=5;
    double volume=volumeSphere(radius);
    cout<<"Volume of sphere is ";
    cout<<volume<<"\n";
    return 0;
}