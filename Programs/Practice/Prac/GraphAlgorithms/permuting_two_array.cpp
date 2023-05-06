#include <bits/stdc++.h>
using namespace std;

string twoArrays(int k, vector<int> A, vector<int> B)
{
    int flag = 0;

    //sort the first array in ascending order
    sort(A.begin(), A.end());

    //sort second array into descesnding order
    sort(B.begin(), B.end(), greater<>());

    int n = A.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] + B[i] < k)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return "YES";
    else
        return "NO";
}
int main()
{

    vector<int> A = {2, 1, 3};
    vector<int> B = {7, 8, 9};
    int k = 10;

    cout << twoArrays(k, A, B);

    return 0;
}
