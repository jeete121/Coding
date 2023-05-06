#include <bits/stdc++.h>
using namespace std;


class Queue {
    int front1 = -1;
    int rear1 = -1;
    // initialize the default capacity
     int DEFAULT_CAPACITY = 10;
    // array
     int array[10];
   public:
    // constructor with capacity
    Queue(int maxSize) {
        this->DEFAULT_CAPACITY = maxSize;
        array[DEFAULT_CAPACITY];
    }

    // constructor with default capacity
   Queue() {
      array[DEFAULT_CAPACITY];
    }

    // add value in queue
void enQueue(int number) {
        // if not full, then add else Overflow
        if (!isFull()) {
            front1++;
            array[front1] = number;
        } else {
            cout<<"Overflow!! ";
        }
    }

// get front and front remove element from queue
    void deQueue() {
        if (!this->isEmpty()) {
            {
                ++rear1;
            }
        } else {
            // reset
            front1 = -1;
            rear1 = -1;
            cout<<"Underflow!! ";
        }
    }

    // only get front element from queue
    int front() {
        if (!this->isEmpty()) {
            if (rear1 == -1) {
                return array[0];
            }
            return array[rear1];
        } else {
            cout<<"Underflow!! ";
            return INT_MIN;
        }
    }

     int size() {
        return front1 - rear1;
    }

    bool isEmpty() {
        return front1 == -1 || front1== rear1;
    }

    bool isFull() {
        return front1 == DEFAULT_CAPACITY - 1;
    }

};
int main()
{
     // create queue with size
      Queue s(3);
     // push 1 element
     cout<<"enQueue(1): ";
     s.enQueue(1);
     cout<<": isEmpty(): "<<s.isEmpty();
     cout<<": front() : "<<s.front();
     cout<< ": Size() : "<<s.size()<<"\n";
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
    cout<<": Size() : " + s.size()<<"\n";
    // push another element
    cout<<"enQueue(3): ";
    s.enQueue(3); 
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": front() : " <<s.front();
    cout<<": Size() : " + s.size()<<"\n";
    // push another element
    cout<<"enQueue(4): ";
    s.enQueue(4);
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": front() : "<<s.front();
    cout<<": Size() : "<<s.size()<<"\n";
    return 0;
}
