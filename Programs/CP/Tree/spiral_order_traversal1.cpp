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
void SpiralOrderTraversal(Node *root)
{
  if(root==nullptr)
     return;
  list<Node*> deque;
  deque.push_front(root);
  bool flag=false;
  while(!deque.empty())
    {
        int n=deque.size();
        if(flag==false)
         {
             while(n)
              {
                  Node *curr=deque.front();
                  deque.pop_front();
                  cout<<curr->key<<" ";
                  if(curr->left)
                    deque.push_back(curr->left);
                  if(curr->right)
                     deque.push_back(curr->right);
                n--;
              }
         }
         else
         {
            while(n)
             {
                 Node *curr=deque.back();
                 deque.pop_back();
                 cout<<curr->key<<" ";
                 if(curr->right)
                   deque.push_front(curr->right);
                  if(curr->left)
                    deque.push_front(curr->left);
                n--;
             }
         }
         flag=!flag;
         cout<<endl;
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
    SpiralOrderTraversal(root);
    return 0;
}
