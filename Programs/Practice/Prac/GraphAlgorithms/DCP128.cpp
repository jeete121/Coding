#include <bits/stdc++.h>
using namespace std;

//function to find the moves in tower of hanoi problem
void move(int n, char source, char destination, char inter)
{

    //base case if only one left
    if (n == 1)
        cout << "Move from " << source << " to " << destination << "\n";

    //else call for n-1
    else
    {
        move(n - 1, source, inter, destination);
        move(1, source, destination, inter);
        move(n - 1, inter, destination, source);
    }
}
int main()
{
    int n = 3;

    //call for n,source,destination,intermediate
    move(n, '1', '2', '3');
    return 0;
}