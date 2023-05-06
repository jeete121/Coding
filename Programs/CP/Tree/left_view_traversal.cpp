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
void LeftView(Node *root)
{
    if(root==nullptr)
      return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
     {
         int n=q.size();
         int i=0;
         while(i++<n)
          {
              Node *curr=q.front();
              q.pop();
              if(i==1)
                cout<<curr->key<<" ";
              if(curr->left)
                q.push(curr->left);
              if(curr->right)
                q.push(curr->right);
          }
     }
}
int main()
{
    Node* root = nullptr;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    LeftView(root);
    return 0;
}