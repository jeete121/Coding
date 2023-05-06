/*
 Check if data in linked list is palindrome or not
 Time Complexity: O(N) where N are number of nodes
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    string str;
    Node *next;
};
Node *newNode(string str)
{
    Node *new_node=new Node;
    new_node->str=str;
    new_node->next=NULL;
    return new_node;
}
bool isPalindrome(Node *head)
{
    if(head==NULL)
       return true;
    string res="";
    while(head!=NULL)
       {
           res+=head->str;
           head=head->next;
       }
     for(int i=0;i<res.size()/2;i++)
        if(res[i]!=res[res.size()-1-i])
           return false;
    return true;
}
int main()
{
 Node *head=newNode("a");
 head->next=newNode("bc");
 head->next->next=newNode("d");
 head->next->next->next=newNode("dcb");
 head->next->next->next->next=newNode("a");
 if(isPalindrome(head))
   cout<<"Data in linked list is palindrome\n";
 else
   cout<<"Data in linked list is not palindrome\n";
 Node *head1=newNode("a");
 head1->next=newNode("bc");
 head1->next->next=newNode("d");
 head1->next->next->next=newNode("ba");
  if(isPalindrome(head1))
   cout<<"Data in linked list is palindrome\n";
 else
   cout<<"Data in linked list is not palindrome\n";
  return 0;
}