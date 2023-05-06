#include <bits/stdc++.h>
using namespace std;
struct  Node
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
void AlternateLevelOrderTraverasl(Node *root)
{
    if(root==nullptr)
      return;
    queue<Node*> q1;
    queue<Node*>q2;
    cout<<root->key<<" ";
    q1.push(root->left);
    q2.push(root->right);
    while(!q1.empty())
     {
        int n=q1.size();
        while(n--)
        {
         Node *x=q1.front();
         q1.pop();
         cout<<x->key<<" ";
         if(x->left)
           q1.push(x->left);
        if(x->right)
           q1.push(x->right);
        Node *y=q2.front();
        q2.pop();
        cout<<y->key<<" ";
        if(y->right)
          q2.push(y->right);
        if(y->left)
          q2.push(y->left);
     }
     }
}
int main()
{
    Node* root = nullptr;    
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    AlternateLevelOrderTraverasl(root);
    return 0;
}