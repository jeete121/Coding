#include <bits/stdc++.h>
using namespace std;

void profilePicture(int l, int w, int h)
{
    if (w < l || h < l)
        cout << "UPLOAD ANOTHER\n";
    else if (w == h && w >= l && h >= l)
        cout << "ACCEPTED\n";
    else
        cout << "CROP IT\n";
}

int main()
{
    int l = 180;

    int w = 640, h = 480;

    profilePicture(l, w, h);

    return 0;
}