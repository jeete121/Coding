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
Node *insert(Node *head,int key)
{
  if(head==nullptr)
    return newNode(key);
  if(head->key>key)
    head->left=insert(head->left,key);
  else
    head->right=insert(head->right,key);
 return head;
}
void inorder(Node *head,queue<int> &q)
{
  if(head==nullptr)
     return;
  inorder(head->left,q);
  q.push(head->key);
  inorder(head->right,q);
}
void preorder(Node *head,queue<int> &q)
{ 
  if(head==nullptr)
     return;
  head->key=q.front();
  q.pop();
  preorder(head->left,q);
  preorder(head->right,q);
}
void printLevelOrderTraversal(Node *head)
{
    if(head==nullptr)
      return;
    queue<Node*> q;
    q.push(head);
    while(!q.empty())
      {
          int n=q.size();
          while(n--)
           {
               Node *node=q.front();
               q.pop();
               cout<<node->key<<" ";
               if(node->left)
                 q.push(node->left);
               if(node->right)
                 q.push(node->right);
           }
         cout<<"\n";
      }
}
void convert(Node *head)
{
    queue<int> q;
    inorder(head,q);
    preorder(head,q);
}
int main()
{
	Node* root = nullptr;
	vector<int> keys = { 5, 3, 2, 4, 8, 6, 10 };
	for (int key: keys)
		root = insert(root, key);
	convert(root);
	printLevelOrderTraversal(root);
	return 0;
}