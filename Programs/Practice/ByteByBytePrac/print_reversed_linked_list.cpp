#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
void printReversedList(Node *n)
{
    if(n==nullptr)
       return;
    printReversedList(n->next);
    cout<<n->value<<" ";
}
int main()
{
   int n,x;
   cout<<"Enter number of elements:\n";
   cin>>n;
   Node *root=nullptr;
   Node *temp=root;
   for(int i=0;i<n;i++)
     {
         cin>>x;
         Node *newNode =new Node();
         newNode->value=x;
         newNode->next=nullptr;
         if(temp==nullptr)
            {
              temp=newNode;
              root=newNode;    
            }
          else
          {
              temp->next=newNode;
              temp=newNode;
          }
     }
     printReversedList(root);
     return 0;
}