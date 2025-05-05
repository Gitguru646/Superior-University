
//#include <iostream>
//using namespace std;
//#define MAX 5
// 
//
//class Stack {
//private:
//
//    int arr[MAX];
//    int top;
//
//public:
//   
//    Stack() {
//        top = -1;
//    }
//
//   
//    void push(int value) {
//        if (top == MAX - 1) {
//            cout << "Stack Overflow! Cannot push " << value << " into the stack." << endl;
//            return;
//        }
//        arr[++top] = value;
//        cout << value << " pushed into the stack." << endl;
//    }
//
//    
//    void pop() {
//        if (top == -1) {
//            cout << "Stack Underflow! Cannot pop from the stack." << endl;
//            return;
//        }
//        cout << arr[top--] << " popped from the stack." << endl;
//    }
//
//  
//    void display() {
//        if (top == -1) {
//            cout << "Stack is empty." << endl;
//            return;
//        }
//        cout << "Stack elements: ";
//        for (int i = 0; i <= top; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//int main() {
// 
//    Stack stack;
//
//    stack.push(10);
//    stack.push(20);
//    stack.push(30);
//    stack.push(40);
//    stack.push(50);
//
//    
//    stack.display();
//    stack.push(60);
//    stack.pop();
//
//    
//    stack.display();
//
//    return 0;
//}







#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() { top = NULL; }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display(); 
    stack.pop();
    stack.display(); 
    return 0;
}

