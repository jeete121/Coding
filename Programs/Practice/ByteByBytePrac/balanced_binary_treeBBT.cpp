#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int value;
  Node *left,*right;
    Node(int value)
    {
        this->value=value;
        this->left=nullptr;
        this->right=nullptr;
    }
};
int balancedHeight(Node *n)
{
    if(n==nullptr)
       return 0;
    int h1=balancedHeight(n->left);
    int h2=balancedHeight(n->right);
    if(h1==-1||h2==-1)
       return -1;
    if(abs(h1-h2)>1)
        return -1;
    if(h1>h2)
       return h1+1;
    return h2+1;
}
   
bool isBalanced(Node *n)
{
    if(balancedHeight(n)>-1)
        return true;
    return false;
}
int main()
{
 Node* root = nullptr;    
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
   // root->left->left->left = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    if(isBalanced(root))
       cout<<"Tree is Balanced";
    else
       cout<<"Tree is not Balanced";
   return  0;
}