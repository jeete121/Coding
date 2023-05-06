#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4, i;

    int grade[n] = {73, 67, 38, 33};

    for (i = 0; i < n; i++)
    {
        if (grade[i] >= 38)
        {
            if (grade[i] % 10 > 2 && grade[i] % 10 < 5)
            {
                if (grade[i] % 10 == 3)
                    grade[i] = grade[i] + 2;
                else
                    grade[i] = grade[i] + 1;
            }
            if (grade[i] % 10 > 7 && grade[i] % 10 <= 9)
            {
                if (grade[i] % 10 == 8)
                    grade[i] = grade[i] + 2;
                else
                    grade[i] = grade[i] + 1;
            }
        }
        else if (grade[i] < 38)
        {
            grade[i] = grade[i];
        }
    }
    for (i = 0; i < n; i++)
        cout << grade[i] << endl;
    return 0;
}
