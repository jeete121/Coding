#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node(int val) 
     {
      this->val=val;
      this->next=NULL;
      this->right=NULL;
      this->left=NULL;
      }

};

//dfs function 
void dfs(Node *root)
{

    //if tree is empty
    if(root==NULL)
              return;

    //if left is not null then point 
    //left next to right
    if(root->left)
        root->left->next=root->right;

    //if right is not null then point right next as 
    //if root next posible the root next left else
    //null
    if(root->right)
         root->right->next=root->next?root->next->left:NULL;
        
    //call for left subtree
    dfs(root->left);

    //call for right subtree
    dfs(root->right);
}
Node* connect(Node* root) 
{
   //if empty tree
    if(root==NULL)
           return NULL;
    
    //at level 0
    root->next=NULL;

    //call dfs 
    dfs(root);
    return root;
}

//function to print the tree
void printTree(Node *root)
{
    queue<Node*>q;
    q.push(root);
    vector<string> vec;
    while(!q.empty())
     {
         int len=q.size();
         while(len--)
         {  
           root=q.front();
           q.pop();
        
           
        if(root!=NULL)
          {
               vec.push_back(to_string(root->val));
              q.push(root->left);
              q.push(root->right);
          }
         }
         vec.push_back("#");
     }
      for(int i=0;i<vec.size()-2;i++)
        cout<<vec[i]<<",";
     cout<<vec[vec.size()-2];
}
int main()
{
  Node *root=new Node(1);
  root->left=new Node(2);
  root->right=new Node(3);
  root->left->left=new Node(4);
  root->left->right=new Node(5);
  root->right->left=new Node(6);
  root->right->right=new Node(7);
  Node *root1=connect(root);
  printTree(root1);
  return 0;
}