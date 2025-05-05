//
//#include <iostream>
//using namespace std;
//
//#define MAX 5
//
//class Queue {
//    int arr[MAX];
//    int front, rear;
//
//public:
//    Queue() { front = rear = -1; }
//
//    void enqueue(int value) {
//        if (rear == MAX - 1) {
//            cout << "Queue is full." << endl;
//            return;
//        }
//        if (front == -1) front = 0;
//        arr[++rear] = value;
//    }
//
//    void dequeue() {
//        if (front == -1 || front > rear) {
//            cout << "Queue is empty." << endl;
//            return;
//        }
//        cout << "Dequeued: " << arr[front++] << endl;
//    }
//
//    void display() {
//        if (front == -1 || front > rear) {
//            cout << "Queue is empty." << endl;
//            return;
//        }
//        for (int i = front; i <= rear; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    Queue queue;
//    queue.enqueue(10);
//    queue.enqueue(20);
//    queue.enqueue(30);
//    queue.display(); 
//    queue.dequeue(); 
//    queue.display(); 
//    return 0;
//}



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() { front = rear = NULL; }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display(); 
    queue.dequeue(); 
    queue.display(); 
    return 0;
}


