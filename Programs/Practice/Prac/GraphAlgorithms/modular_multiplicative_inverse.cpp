#include <bits/stdc++.h>
using namespace std;

//functoon to return GCD and find the
//coefficient x any y
//of the equation a*x+b*y=gcd(a,b)
int gcd(int a, int b, int &x, int &y)
{

    //base case
    if (b == 0)
    {
        //set x=1
        x = 1;

        //set y=0
        y = 0;
        return a;
    }

    //intermediate variables
    int x1, y1;

    //now call the gcd function
    int d = gcd(b, a % b, x1, y1);

    //formaula for x as x= y1
    x = y1;

    //formula for  y as x1-y1*(a/b)
    y = x1 - y1 * (a / b);

    //return the gcd
    return d;
}
int main()
{
    int a = 3, m = 26;
    int x, y;
    int d = gcd(a, m, x, y);
    if (d != 1)
    {
        cout << "No modular inverse!";
    }
    else
    {
        x = (x % m + m) % m;
        cout << x << endl;
    }

    return 0;
}

//Time Complexity: O(log(min(a,b)))
