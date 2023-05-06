#include <bits/stdc++.h>
using namespace std;

double average(vector<int> &salary)
{
    sort(salary.begin(), salary.end());
    double d = 0;
    int n = salary.size();
    for (int i = 1; i < n - 1; i++)
        d += salary[i];
    return d / (n - 2);
}

int main()
{
    vector<int> salary = {4000, 3000, 1000, 2000};
    cout << average(salary);
    return 0;
}