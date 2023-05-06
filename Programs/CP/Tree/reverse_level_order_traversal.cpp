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

void ReverseLevelOrderTraversal(Node *root)
{
    if(root==nullptr)
      return;
    queue<Node*> q;
    q.push(root);
    stack<int> st;
    while(q.size())
     {
        Node *curr=q.front();
         q.pop();
         st.push(curr->key);
        if(curr->right)
            q.push(curr->right);
         if(curr->left)
           q.push(curr->left);
     }
     while(!st.empty())
      {
          cout<<st.top()<<" ";
          st.pop();
      }
}
int main()
{
    Node* root = nullptr;
    root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
    ReverseLevelOrderTraversal(root);
    return 0;
}