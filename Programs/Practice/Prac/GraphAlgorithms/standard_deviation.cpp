#include <bits/stdc++.h>
using namespace std;

double standardDeviation(vector<int> &arr)
{
    double answer = 0;
    double mean = 0;
    double sum = 0;

    int N = arr.size();

    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    mean = sum / N;

    for (int i = 0; i < N; i++)
    {
        answer += pow(arr[i] - mean, 2);
    }

    return sqrt(answer / N);
}

int main()
{

    vector<int> arr = {3, 4, 2, 5, 6, 2};

    cout << standardDeviation(arr);

    return 0;
}