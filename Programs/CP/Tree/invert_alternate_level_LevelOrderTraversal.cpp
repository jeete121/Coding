#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left,*right;
};
Node *newNode(int key)
{
  Node *node=new Node;
  node->key=key;
  node->left=nullptr;
  node->right=nullptr;
  return node;
}
void LevelOrderTraversal(Node *root)
{
    if(root==nullptr)
       return;
    queue<Node*>q;
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
void invertLevel(Node *root)
{
    if(root==nullptr)
      return;
    queue<Node*>q;
    q.push(root);
    bool level=false;
    queue<Node*> level_nodes;
    stack<int> level_data;
    while(!q.empty())
     {
         int n=q.size();
         while(n--)
           {
            Node *curr=q.front();
            q.pop();
            if(level)
              {
                  level_nodes.push(curr);
                  level_data.push(curr->key);
              }   
             if(n==0)
              {
                  level=!level;
                while(!level_nodes.empty())
                {
                  Node *temp=level_nodes.front();
                  temp->key=level_data.top();
                  level_nodes.pop();
                  level_data.pop();
                }
              }
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
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(11);
	root->right->left->left = newNode(12);
	root->right->left->right = newNode(13);
	root->right->right->left = newNode(14);
	root->right->right->right = newNode(15);
	invertLevel(root);
	LevelOrderTraversal(root);
	return 0;
}