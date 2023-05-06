#include <bits/stdc++.h>
using namespace std;
//function to find the perimeter
//of the kite
double perimeterKite(double first_pair,double second_pair)
{
    double perimeter=2*first_pair+2*second_pair;
    return perimeter;

}
int main()
{
    double first_pair=3;
    double second_pair=4;
    double perimeter=perimeterKite(first_pair,second_pair);
    cout<<"Perimeter of Kite is ";
    cout<<perimeter<<"\n";
    return 0;
}