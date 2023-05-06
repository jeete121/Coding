#include <bits/stdc++.h>
using namespace std;
//Struture of  node
struct Node
{ 
   int data;
   Node *next;
   Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
//function to check the given
//node is present in linked list
bool searchElement(Node *head,int target)
{
    //if linked list is empty
    //return -1
    if(head==NULL)
       return false;
    //node to store the head of
    //the linked list
     Node *temp=head;
     //iterate till end of list or
     //count becomes n
     while(temp!=NULL)
      {
       
          //if current node data
          //is same as the target value
          //the return true
          if(temp->data==target)
              return true;
        //move to the next node
          else
            temp=temp->next;
      }
    //if element is not found
    //in linked list return false
     return false;
}
int main()
{
  Node *head=new Node(5);
  head->next=new Node(2);
  head->next->next=new Node(8);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(1);
  int target=8;
  if(searchElement(head,target))
     cout<<"Element is found\n";
  else
   cout<<"Element is not found\n";
  return 0;
}
//Time Complexity: O(n)
//Space Complexity:O(1)