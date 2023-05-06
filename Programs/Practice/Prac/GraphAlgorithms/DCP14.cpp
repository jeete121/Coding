#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i;
    int nThrows = 0;
    int nSuccess = 0;

    double x, y;
    double pi;

    for (i = 0; i < 10000; i++)
    {
        x = double(rand() % (1000 + 1)) / 1000;
        y = double(rand() % (1000 + 1)) / 1000;

        nThrows++;

        if (x * x + y * y <= 1)
            nSuccess++;
        pi = (4 * (double)nSuccess) / (double)nThrows;
    }
    cout << pi << "\n";

    return 0;
}
