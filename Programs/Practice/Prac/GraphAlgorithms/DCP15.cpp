#include <bits/stdc++.h>
using namespace std;

int random_element(vector<int> &stream)
{

    int size = stream.size();
    int rnd = rand() % size;
    return stream[rnd];
}

int main()
{
    vector<int> stream = {22, 44, 33, 55};
    for (int i = 0; i < 10; i++)
    {
        cout << random_element(stream) << " ";
    }
    return 0;
}