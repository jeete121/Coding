#include <bits/stdc++.h>
using namespace std;
set<int> uniqueDigits(int a)
{
    set<int> st;
    while (a)
    {
        st.insert(a % 10);
        a = a / 10;
    }
    return st;
}

int digitalSequence(int n, int arr[])
{
    int max1 = INT_MIN;
    for (int i = 0; i <= 9; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            int x = arr[j];
            set<int> st = uniqueDigits(x);
            if (st.find(i) != st.end())
                cnt++;
        }
        max1 = max(max1, cnt);
    }
    return max1;
}
int main()
{
    int n = 5;

    int arr[n] = {12, 11, 3, 4, 5};

    cout << digitalSequence(n, arr) << "\n";

    return 0;
}