#include <bits/stdc++.h>
using namespace std;

int ballroomDance(int n, int a[], int m, int b[])
{
    bool visited[m] = {false};
    int cnt = 0;
    sort(a, a + n);
    sort(b, b + m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = abs(a[i] - b[j]);
            if (visited[j] == false && x <= 1)
            {
                visited[j] = true;
                cnt++;

                break;
            }
        }
    }
    return cnt;
}
int main()
{
    int n = 4;
    int a[n] = {1, 4, 6, 2};

    int m = 5;
    int b[m] = {5, 1, 5, 7, 9};

    cout << ballroomDance(n, a, m, b) << "\n";

    return 0;
}