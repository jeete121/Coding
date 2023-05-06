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
Node *construct(queue<int> &q)
{
    queue<Node*> node;
    Node *root=newNode(q.front());
    q.pop();
    node.push(root);
    while(!q.empty())
     {
         Node *parent=node.front();
         node.pop();
         parent->left=newNode(q.front());
         q.pop();
         node.push(parent->left);
         if(!q.empty())
           {
               parent->right=newNode(q.front());
               q.pop();
               node.push(parent->right);
           }
     }
     return root;
}
void convert(Node* &head)
{
    queue<int> q;
    inorder(head,q);
    head=construct(q);
}
int main()
{
	Node* root = nullptr;
	vector<int> keys = { 5, 3, 2, 4, 8, 10 };
	for (int key: keys)
		root = insert(root, key);
	convert(root);
	printLevelOrderTraversal(root);
	return 0;
}