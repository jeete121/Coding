#include <bits/stdc++.h>
using namespace std;

int diwaliCelebration(int a, int n, int k)
{
    int ans = a + n * (k - 1);
    return ans;
}
int main()
{
    int a = 10, n = 3, k = 5;

    cout << diwaliCelebration(a, n, k) << "\n";

    return 0;
}