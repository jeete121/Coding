#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3] = {17, 28, 30}, b[3] = {99, 16, 8};
    int alice_point = 0, bob_point = 0;
    for (int i = 0; i < 3; i++)
    {
        if (a[i] > b[i])
        {
            alice_point++;
        }
        if (b[i] > a[i])
        {
            bob_point++;
        }
    }
    cout << alice_point << " " << bob_point << "\n";
    return 0;
}
