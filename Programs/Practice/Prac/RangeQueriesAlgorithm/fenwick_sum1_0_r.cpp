#include <bits/stdc++.h>
using namespace std;
int bit[101];
int arr[101];
int n;

//function to find the elements tille r
int sum(int r)
{
  int res = 0;
  while (r >= 0)
  {
    res += bit[r];
    r = (r & (r + 1)) - 1;
  }
  return res;
}

//function to get the sum from
//l to  r
int sum(int l, int r)
{
  return sum(r) - sum(l - 1);
}

//function to add the value in
//fenwick tree
void add(int idx, int delta)
{
  while (idx < n)
  {
    bit[idx] += delta;
    idx = idx | (idx + 1);
  }
}

//function to buils the tree
void buildTree()
{
  for (int i = 0; i < n; i++)
    add(i, arr[i]);
}
int main()
{
  n = 5;
  arr[0] = 3;
  arr[1] = 2;
  arr[2] = 1;
  arr[3] = 4;
  arr[4] = 5;
  buildTree();

  int l = 2, r = 4;

  cout << sum(l, r) << "\n";

  return 0;
}