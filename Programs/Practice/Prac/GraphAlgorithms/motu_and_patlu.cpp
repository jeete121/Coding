#include <bits/stdc++.h>
using namespace std;

void motuPatlu(int n, vector<float> &a)
{
    int i = 0, j = a.size() - 1, cnt1 = 0, cnt2 = 0;
    int lasti = -1, lastj = a.size();
    while (i < j)
    {
        if (a[i] < 2 * a[j])
        {

            a[j] -= a[i] / 2;
            a[i] = 0;
            lasti = i, lastj = j;
            cnt1++;
            i++;
        }
        else if (a[i] > 2 * a[j])
        {
            a[i] -= a[j] * 2;
            a[j] = 0;
            lasti = i;
            lastj = j;
            cnt2++;
            j--;
        }
        else if (a[i] == 2 * a[j])
        {
            a[i] = 0;
            a[j] = 0;

            lasti = i;
            lastj = j;
            cnt1++;
            cnt2++;
            i++;
            j--;
        }
    }
    if (i == j)

    {

        if (lasti == i && lastj != j)

            cnt1++;

        else if (lasti != i && lastj == j)

            cnt2++;

        else if (lasti != i && lastj != j)

        {
            cnt1++;
        }
    }
    cout << cnt1 << " " << cnt2 << "\n";
    if (cnt1 == cnt2)
        cout << "Tie\n";
    else if (cnt1 > cnt2)
        cout << "Motu\n";
    else
        cout << "Patlu\n";
}
int main()
{

    int n = 5;
    vector<float> a = {2, 6, 2, 1, 7};

    motuPatlu(n, a);

    return 0;
}