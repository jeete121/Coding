#include <bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> res;
    for (int i = 1; i <= n; i++)
    {
        if (i % 15 == 0)
            res.push_back("FizzBuzz");
        else if (i % 5 == 0)
            res.push_back("Buzz");
        else if (i % 3 == 0)
            res.push_back("Fizz");
        else
            res.push_back(to_string(i));
    }
    return res;
}

int main()
{
    int n = 15;
    vector<string> res = fizzBuzz(n);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ",";
    }
    cout << res[res.size() - 1] << "]";

    return 0;
}