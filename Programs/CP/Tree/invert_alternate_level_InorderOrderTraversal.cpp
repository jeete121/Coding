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
    while(q.size())
      {
         Node  *curr=q.front();
          q.pop();
          cout<<curr->key<<" ";
          if(curr->left)
            q.push(curr->left);
          if(curr->right)
            q.push(curr->right);
      }
}
void pushOddLevelNodes(Node *root,stack<int> &st,bool level)
{
   if(root==nullptr)
      return;
    pushOddLevelNodes(root->left,st,!level);
    if(level)
      st.push(root->key);
    pushOddLevelNodes(root->right,st,!level);
}
void invertLevel(Node *root,stack<int> &st,bool level)
{
    if(root==nullptr)
       return;
    invertLevel(root->left,st,!level);
    if(level)
     {
      root->key=st.top();
      st.pop();
     }
    invertLevel(root->right,st,!level);
}
void invertBinaryTree(Node *root)
{
    stack<int> st;
    pushOddLevelNodes(root,st,false);
    invertLevel(root,st,false);
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
	invertBinaryTree(root);
	LevelOrderTraversal(root);
	return 0;
}