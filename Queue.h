
//File: Queue.h
//Description: FRIENDQUEUE


#ifndef FRIENDQUEUE_QUEUE_H
#define FRIENDQUEUE_QUEUE_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename DataType>

class Queue {

private:
    struct Node {
        DataType data;
        Node* next;
        Node* prev;

        //Node Constructor
        //Purpose: Create and initialize Node
        //Parameters: DataType data node value, Node* next pointer, Node* prev previous pointer
        //Post-Conditions: Node is created and initialized with data and pointers
        explicit Node(const DataType& data, Node* next = nullptr, Node* prev = nullptr) : data(data), next(next), prev(prev) {}
    };

    Node* front;
    Node* rear;
    int count;

public:

    //Queue Constructor
    //Purpose: Create an empty Queue
    //Parameters: None
    //Post-Conditions: Queue is created and initialized with count of 0
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    //Queue Copy Constructor
    //Purpose: Create Queue with deep copy of another Queue
    //Parameters: const Queue& original
    //Post-Conditions: Queue created becomes a deep copy of 'original' Queue
    Queue(const Queue& original) : front(nullptr), rear(nullptr), count(0) {
        Node* current = original.front;
        while (current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }
    }

    //Queue Destructor
    //Purpose: Deallocate nodes in Queue (deallocate memory)
    //Parameters: None
    //Post-Conditions: Dynamically allocated memory is deallocated
    ~Queue() {
        makeEmpty();
    }

    //enqueue Function
    //Purpose: Add element to end of Queue
    //Parameters: const DataType& element
    //Post-Conditions: Element is added to the end of Queue, count is increased
    void enqueue(const DataType& element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        count++;
    }

    //dequeue Function
    //Purpose: Remove and return element at the front of Queue
    //Parameters: None
    //Post-Conditions: Front element is removed and data returned, count is decreased or underflow_error is thrown
    DataType dequeue() {
        if (isEmpty()) throw underflow_error("Queue is empty");
        Node* temp = front;
        DataType data = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
        count--;
        return data;
    }

    //isEmpty Function
    //Purpose: Check if Queue is empty
    //Parameters: None
    //Post-Conditions: Returns true if empty and false if not empty
    bool isEmpty() const {
        return count == 0;
    }

    //makeEmpty Function
    //Purpose: Remove all elements in Queue
    //Parameters: None
    //Post-Conditions: Queue is empty, dynamic memory is deallocated
    void makeEmpty() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    //peek Function
    //Purpose: Return data of front element
    //Parameters: None
    //Post-Conditions: Front element data is returned or underflow_error is thrown
    DataType peek() const {
        if (isEmpty()) throw underflow_error("Queue is empty");
        return front->data;
    }

    //print Function
    //Purpose: Print all elements in Queue, front to back
    //Parameters: None
    //Post-Conditions: All elements are output to console in order
    void print() const {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    //reversePrint Function
    //Purpose: Print all elements in Queue, back to front
    //Parameters: None
    //Post-Conditions: All elements are output to console in reverse order
    void reversePrint() const {
        Node* current = rear;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->prev;
        }
    }
};

#endif //FRIENDQUEUE_QUEUE_H
