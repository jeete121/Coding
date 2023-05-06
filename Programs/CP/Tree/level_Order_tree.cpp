#include <bits/stdc++.h>
using namespace std;
struct Node 
{
  int key;
  Node *left,*right;
  Node(int key)
  {
  this->key=key;
  this->left=nullptr;
  this->right=nullptr;
  }

};
void LevelOrder(Node *root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
     {
         Node *curr=q.front();
         q.pop();
         cout<<curr->key<<" ";
         if(curr->left)
            q.push(curr->left);
          if(curr->right)
            q.push(curr->right);
     }
}
int main()
{
    Node* x = nullptr;
    x = new Node(15);
    x->left = new Node(10);
    x->right = new Node(20);
    x->left->left = new Node(8);
    x->left->right = new Node(12);
    x->right->left = new Node(16);
    x->right->right = new Node(25);
    LevelOrder(x);
    return 0;
}