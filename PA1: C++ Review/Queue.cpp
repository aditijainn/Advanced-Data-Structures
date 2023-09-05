#include "Queue.h"

/**
 * Implement Queue constructor
 */
Queue::Queue() {
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

/**
 * Implement the Queue destructor
 */
Queue::~Queue() {
    clear();
    numElements = 0;
}

/**
 * Implement size() correctly
 */
unsigned int Queue::size() {
    return numElements;
}
/**
 * Implement clear() correctly without memory leaks
 */
void Queue::clear() {
    Node* curr = head;

    while(curr != nullptr) {
        Node* temp = curr;
        delete temp;
        curr = curr->next;
    }
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

/**
 * Implement push() correctly
 */
void Queue::push(string s) {
    Node* curr = new Node(s);
    
    if(head == nullptr || tail == nullptr) {
        tail = curr;
        head = curr;
        numElements++;
    }
    else {
        tail-> next = curr;
        tail = curr;
        numElements++;
    }
}

/**
 * Implement pop() correctly without memory leaks
 */
string Queue::pop() {

    if(head == tail) {
        Node* output = head;
        head = nullptr;
        tail = nullptr;
        string data = output->data;  
        numElements = 0;
        delete output;
        return data;
    }
    Node* output = head;
    head = head->next;
    numElements--;
    string data2 = output->data;
    delete output;
    return data2;
}
