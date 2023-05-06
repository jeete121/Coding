// conversion with cast operator
#include<iostream>
#include <bits/stdc++.h>
#include<conio.h>
using namespace std;
class Item;
class Product
{
 private:
     int m,n;
 public:
    void setData(int x,int y)
     {
       m=x;
       n=y;
     }
    vector<int> get_num() 
      { 
         return {m,n};
      }
};
class Item
{
  private:
    int a,b;
  public:
    void operator=(Product n)
     {
      vector<int> v=n.get_num();
      a=v[0];
      b=v[1];
    }
  void showData()
  {
  cout<<"\na="<<a<<" b="<<b;
  }

};

int main()
{
  Item i1;  // default constructor
  Product p1;
  p1.setData(3,4);
  i1=p1;
  i1.showData();
  getch();
}
