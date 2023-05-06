#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value=value;
        this->left=nullptr;
        this->right=nullptr;
    }
};
Node *concatenate(Node *a,Node *b)
{
    if(a==nullptr)
      return b;
    if(b==nullptr)
      return a;
    Node *aEnd=a->left;
    Node *bEnd=b->left;
    a->left=bEnd;
    bEnd->right=a;
    aEnd->right=b;
    b->left=aEnd;
    return a;
}
Node *treeToList(Node *n)
{
    if(n==nullptr)
       return n;
    Node *leftList=treeToList(n->left);
    Node *rightList=treeToList(n->right);
    n->left=n;
    n->right=n;
    n=concatenate(leftList,n);
    n=concatenate(n,rightList);
    return n;
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
    Node *x=treeToList(root);
    Node *temp=x;
    cout<<temp->value<<" ";
     temp=temp->right;
    while(temp!=x)
           {
               cout<<temp->value<<" ";
               temp=temp->right;
           }       
    return 0;
}