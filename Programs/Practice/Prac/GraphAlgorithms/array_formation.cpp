#include <bits/stdc++.h>
using namespace std;

bool prime[1000001];
void primeInitialize()
{

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= 1000001; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000001; j += i)
                prime[j] = false;
        }
    }
}

void arrayFormation(int n, int a[])
{
    stack<int> st;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (prime[a[i]])
            q.push(a[i]);
        else
            st.push(a[i]);
    }
    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
    }
    cout << "\n";
    while (!st.empty())
    {
        int x = st.top();
        cout << x << " ";
        st.pop();
    }
    cout << "\n";
}
int main()
{
    int n = 5;

    int a[n] = {7, 21, 18, 3, 12};

    primeInitialize();

    arrayFormation(n, a);

    return 0;
}