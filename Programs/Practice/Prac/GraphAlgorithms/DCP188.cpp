#include <bits/stdc++.h>
using namespace std;

int print_i(int i)
{
    return i;
}
vector<vector<int>> make_functions()
{
    vector<vector<int>> flist;
    vector<int> arr = {1, 2, 3};

    for (int i = 0; i < arr.size(); i++)
    {
        flist.push_back({print_i(arr[i]), i});
    }

    return flist;
}
int main()
{

    vector<vector<int>> functions = make_functions();
    for (int i = 0; i < functions.size(); i++)
        cout << functions[i][0] << " ";

    return 0;
}