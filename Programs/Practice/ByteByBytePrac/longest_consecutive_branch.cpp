#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int value;
    Node *left,*right;
};
Node *newNode(int key)
{
    Node *node=new Node;
    node->value=key;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}
int consecutive(Node *n,int prev,int length)
{
    if(n==nullptr)
       return length;
    if(n->value==prev+1)
      {
          int leftLength=consecutive(n->left,n->value,length+1);
          int rightLength=consecutive(n->right,n->value,length+1);
          return max(leftLength,rightLength);
      }
    else
    {
        int leftLength=consecutive(n->left,n->value,1);
        int rigthLength=consecutive(n->right,n->value,1);
        return max(leftLength,rigthLength);
    }
}
int consecutive(Node *n)
{
    if(n==nullptr)
       return 0;
    return max(consecutive(n->left,n->value,1),consecutive(n->right,n->value,1));
}
int main()
{
  Node *root=nullptr;
  root=newNode(0);
  root->left=newNode(1);
  root->right=newNode(2);
  root->left->left=newNode(1);
  root->left->right=newNode(2);
  root->right->left=newNode(1);
  root->right->right=newNode(3);
  int res=consecutive(root);
  cout<<"Longest Consecutive Brainch:\n";
  cout<<res<<"\n";
  return 0;
}