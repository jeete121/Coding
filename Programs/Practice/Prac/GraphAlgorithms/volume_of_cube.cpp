#include <bits/stdc++.h>
using namespace std;
//function to find the volume of
//cube
double volumeCube(double side)
{
    double volume =side*side*side;
    return volume;
}
int main()
{
    double side=4;
    double volume =volumeCube(side);
    cout<<"Volume of cube is ";
    cout<<volume<<"\n";
    return 0;
}