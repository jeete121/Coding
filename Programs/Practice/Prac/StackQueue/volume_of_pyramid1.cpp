#include <bits/stdc++.h>
using namespace std;

//function to find the volume
//of square base pyramid
double volumeOfPyramid(double length,double height)
{
    //formula =1/3*areaofbase*height
    double volume=(length*length*height)/3;
    return volume;
}
int main()
{
    double length=5;
    double height=12;
    double volume=volumeOfPyramid(length,height);
    cout<<"Volume is ";
    cout<<volume<<"\n";
    return 0;
}