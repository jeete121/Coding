#include <bits/stdc++.h>
using namespace std;

void war(int n, int bob[], int alice[])
{
    sort(alice, alice + n);
    sort(bob, bob + n);
    int max1 = alice[n - 1], max2 = bob[n - 1];
    if (max1 == max2)
        cout << "Tie\n";
    else if (max1 > max2)
        cout << "Alice\n";
    else
        cout << "Bob\n";
}
int main()
{
    int n = 4;

    int bob[n] = {5, 6, 3, 1};
    int alice[n] = {10, 3, 5, 6};

    war(n, bob, alice);

    return 0;
}