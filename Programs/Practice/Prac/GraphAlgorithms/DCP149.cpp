#include <bits/stdc++.h>
using namespace std;

vector<int> sumArray;
void preprocessing(vector<int> &values)
{

    for (int i = 1; i < values.size(); i++)
    {
        sumArray[i] = sumArray[i - 1] + values[i];
    }
}
int sum(int i, int j)
{
    return sumArray[j - 1] - sumArray[i - 1];
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};

    int i = 1, j = 3;
    sumArray.resize(values.size());
    preprocessing(values);

    cout << sum(i, j);
    return 0;
}