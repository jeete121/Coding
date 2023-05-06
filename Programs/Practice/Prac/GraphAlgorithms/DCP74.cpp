#include <bits/stdc++.h>
using namespace std;

int findXAppearsinTable(int n, int x)
{
    vector<int> factors;
    if (x <= 0 || x > n * n)
    {
        return 0;
    }

    //find all the factors of x
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (i == x / i)
            {
                factors.push_back(i);
            }
            else
            {
                factors.push_back(i);
                factors.push_back(x / i);
            }
        }
    }

    //sort the factors
    sort(factors.begin(), factors.end());
    int ans = 0;

    //if x is perfect square
    if (sqrt(x) == int(sqrt(x)))
    {
        ans++;
    }
    for (int i = 0; i < factors.size() / 2; i++)
    {
        int a = factors[i];
        int b = factors[factors.size() - 1 - i];

        //if in the range then update answer
        //anwer will add 2 because the value occurs in
        //the pair
        if (a >= 1 && b <= n)
        {
            ans += 2;
        }
    }
    return ans;
}
int main()
{

    int n = 6;
    int x = 12;

    cout << findXAppearsinTable(n, x);
    return 0;
}