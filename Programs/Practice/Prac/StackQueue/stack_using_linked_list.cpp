#include <bits/stdc++.h>
using namespace std;

class ListNode {   
  public:
    int val;
    ListNode* next;

    ListNode() {
    }

    ListNode(int val) {
        this->val = val;
        this->next=NULL;
    }

    ListNode(int val, ListNode *next) {
        this->val = val;
        this->next = next;
    }
};

class StackList {
    int DEFAULT_CAPACITY = 10;
    ListNode* list = NULL;
    int TOP = -1;

   public:
     StackList(int maxSize) {
        this->DEFAULT_CAPACITY = maxSize;
        this->TOP = -1;
    }

     StackList() {
        this->TOP = -1;
    }

void push(int number) {
        if (!isFull()) {
            TOP++;
            if (TOP == 0)
                list = new ListNode(number);
            else
                {
                    list->next = new ListNode(number);
                }
        } else {
           cout<<"Overflow!! ";
        }
    }
    void popAndDeletionAtEnd() {
        int val = 0;
        ListNode *tmp = list;
        // If list is blank or single node
        if (list == nullptr) {
            return ;
        }
        if (list->next == nullptr) {
            val = list->val;
            list = nullptr;
            return ;
        }
        val = tmp->next->val;

        // Iterate till tmp.next->next is null
        while (tmp->next->next != nullptr) {
            val = tmp->val;
            tmp = tmp->next;
        }
        tmp->next = nullptr;
    }
    void pop() {
        if (!this->isEmpty()) {
            TOP--;
            popAndDeletionAtEnd();
        } else {
            cout<<"Underflow!! ";
        }
    }

  

    int popAtEnd() {
        int val = 0;
        ListNode *tmp = list;
        // If list is blank or single node
        if (list ==NULL) {
            return -1;
        }

        // Iterate till tmp is null
        ListNode *prev = NULL;
        while (tmp !=NULL) {
            prev = tmp;
            tmp = tmp->next;
        }
        val = prev->val;
       return val;
    }

    int peek() {
        if (!this->isEmpty()) {
            return popAtEnd();
        } else {
            cout<<"Underflow!! ";
            return -1;
        }
    }

     int size() {
        return TOP + 1;
    }

    bool isEmpty() {
        return TOP == -1;
    }

    bool isFull() {
        return TOP == DEFAULT_CAPACITY - 1;
    }

};
int main()
{
   // create stack with size
    StackList s(3);
    // push 1 element
    cout<<"Push(1): ";
    s.push(1); 
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Peek() : "<<s.peek();
    cout<<": Size() : "<<s.size()<<"\n";
   // pop element
    cout<<"Peek(): "<<s.peek();
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Pop() : ";
    s.pop();
    cout<<": Size() : "<<s.size()<<"\n";
    // pop element
    cout<<" Peek(): "<<s.peek(); 
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Pop() : ";
    s.pop();
    cout<<": Size() : "<<s.size()<<"\n";
    // push another element
    cout<<" Push(1): ";
    s.push(1); 
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Peek() : "<<s.peek();
    cout<<": Size() : "<<s.size()<<"\n";
    // push another element
    cout<<"Push(2): ";
    s.push(2);
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Peek() : "<<s.peek();
   cout<<": Size() : "<<s.size()<<"\n";
   // push another element
    cout<<"Push(3): ";
    s.push(3); 
   cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Peek() : "<<s.peek();
    cout<<": Size() : "<<s.size()<<"\n";
        // push another element
    cout<<" Push(4): ";
    s.push(4); 
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Peek() : "<<s.peek();
    cout<<": Size() : "<<s.size()<<"\n";
    return 0;
}
   
