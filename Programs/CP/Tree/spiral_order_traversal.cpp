//Time Complexity O(n^2)
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
bool LevelLeftToRight(Node *root,int level)
{
    if(root==nullptr)
      return false;
    if(level==1)
     {
         cout<<root->key<<" ";
         return true;
     }
     bool left=LevelLeftToRight(root->left,level-1);
     bool right=LevelLeftToRight(root->right,level-1);
     return left||right;

}
bool LevelRightToLeft(Node *root,int level)
{
    if(root==nullptr)
      return false;
    if(level==1)
     {
         cout<<root->key<<" ";
         return true;
     }
     bool right=LevelRightToLeft(root->right,level-1);
     bool left=LevelRightToLeft(root->left,level-1);
     return right||left;

}
void spiralOrderTraversal(Node *root)
{
    if(root==nullptr)
      return;
    int level=1;
    while(LevelLeftToRight(root,level++)&&LevelRightToLeft(root,level++));
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
    spiralOrderTraversal(root);
    return 0;
}