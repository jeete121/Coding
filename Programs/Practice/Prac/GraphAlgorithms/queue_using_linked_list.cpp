#include <bits/stdc++.h>
using namespace std;

class ListNode {

public:
    int val;
    ListNode *next;
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
class QueueLink {
    int front1 = -1;
    int rear1 = -1;
    // initialize the default capacity
    int DEFAULT_CAPACITY = 10;
    // linked list
     ListNode* list = NULL;

   public:
    // constructor with capacity
    QueueLink(int maxSize) {
        this->DEFAULT_CAPACITY = maxSize;
    }

    // constructor with default capacity
    QueueLink() {
    }

    // add value in queue
    void enQueue(int val) {
        // if not full, then add else Overflow
        if (!isFull()) {
            // if list is empty
            if (front1 == -1) {
                front1++;
                list = new ListNode(val);
            } else {
                front1++;
                list->next = new ListNode(val);
            }
        } else {
            cout<<"Overflow!! ";
        }
    }

// get front and front remove element from queue
    void deQueue() {
        if (!this->isEmpty()) {
            rear1++;
            searchGivenNode(list, rear1);
        } else {
            // reset
            list = NULL;
            front1 = -1;
            rear1 = -1;
            cout<<"Underflow!! ";
           // return INT_MIN;
        }
    }

    // return nth element from link list
     int searchGivenNode(ListNode *head, int value) {
        int nth = 0;
        while (head != NULL) {
            if (nth == value) {
                return head->val;
            }
            nth++;
            head = head->next;

        }
        return -1;
    }

    // only get front element from queue
    int front() {
        if (!this->isEmpty()) {
            if (rear1 == -1) {
                return list->val;
            }
            return searchGivenNode(list, rear1);
        } else {
            // reset
            list = NULL;
            front1 = -1;
            rear1 = -1;
            cout<<"Underflow!! ";
            return INT_MIN;
        }
    }

    int size() {
        return front1 - rear1;
    }

    bool isEmpty() {
        return front1 == -1 || front1 == rear1;
    }

    bool isFull() {
        return front1== DEFAULT_CAPACITY - 1;
    }

};
int  main()
{
        // create queue with size
        QueueLink s(3);
        // push 1 element
        cout<<"enQueue(1): ";
        s.enQueue(1); 
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": front() : "<<s.front();
         cout<<": Size() : " <<s.size()<<"\n";
        // pop element
        cout<<"front(): "<<s.front(); 
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": deQueue() : ";
        s.deQueue();
        cout<<": Size() : "<<s.size()<<"\n";
        // pop element
        cout<<"front(): "<<s.front(); 
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": deQueue() : ";
        s.deQueue();
        cout<<": Size() : "<<s.size()<<"\n";
        // push another element
        cout<<"enQueue(1): ";
        s.enQueue(1); 
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": front() : "<<s.front();
        cout<<": Size() : "<<s.size()<<"\n";
        // push another element
        cout<<"enQueue(2): ";
        s.enQueue(2); 
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": front() : "<<s.front();
        cout<<": Size() : "<<s.size()<<"\n";
        // push another element
        cout<<"enQueue(3): ";
        s.enQueue(3); 
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": front() : "<<s.front();
        cout<<": Size() : "<<s.size()<<"\n";
        // push another element
        cout<<"enQueue(4): ";
        s.enQueue(4); 
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": front() : "<<s.front();
        cout<<": Size() : " + s.size()<<"\n";
        return 0;

}
