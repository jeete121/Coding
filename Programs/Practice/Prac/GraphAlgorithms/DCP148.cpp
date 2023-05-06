#include <bits/stdc++.h>
using namespace std;

vector<string> GreyCode(int n)
{
    vector<string> vec;

    //base case
    if (n <= 0)
        return vec;

    vec.push_back("0");
    vec.push_back("1");

    for (int i = 2; i < (1 << n); i = i << 1)

    {
        for (int j = i - 1; j >= 0; j--)
            vec.push_back(vec[j]);

        //left side add 0
        for (int j = 0; j < i; j++)
            vec[j] = "0" + vec[j];

        //right side add 1
        for (int j = i; j < 2 * i; j++)
            vec[j] = "1" + vec[j];
    }

    return vec;
}

int main()
{
    int n = 2;
    vector<string> codes = GreyCode(n);

    cout << "[";
    for (int i = 0; i < codes.size(); i++)

    {
        cout << codes[i];
        if (i != codes.size() - 1)
            cout << ", ";
    }

    cout << "]";

    return 0;
}