#include <bits/stdc++.h>
using namespace std;

int designerPdfViewer(vector<int> h, string word)
{
    int m = word.size();
    int c[m];
    int k = 0;
    for (int j = 0; j < m; j++)
    {
        int x = 97;
        while (word[j] != x && x <= 122)
        {
            x++;
        }
        c[k] = h[x - 97];
        k++;
    }
    int large = c[0];
    for (int i = 1; i < m; i++)
    {
        if (c[i] > large)
            large = c[i];
    }
    return large * m;
}

int main()
{

    vector<int> h = {1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    string word = "abc";
    cout << designerPdfViewer(h, word);
    return 0;
}
