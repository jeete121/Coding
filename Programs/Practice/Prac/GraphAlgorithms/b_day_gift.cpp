#include <bits/stdc++.h>
using namespace std;

double solve(vector<int> balls)
{
    double sum = 0;
    for (auto i : balls)
    {
        sum += i;
    }
    return (sum / 2);
}

int main()
{
    int balls_count = 3;
    vector<int> balls = {1, 1, 2};
    double result = solve(balls);

    cout << fixed << setprecision(1) << result << "\n";

    return 0;
}