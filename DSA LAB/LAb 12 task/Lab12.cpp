//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* left;
//    Node* right;
//
//    Node(int value) {
//        data = value;
//        left = right = NULL;
//    }
//};
//
//Node* insert(Node* node, int value) {
//    if (node == NULL) {
//        node = new Node(value);
//    } else if (value < node->data) {
//        node->left = insert(node->left, value);
//    } else if (value > node->data) {
//        node->right = insert(node->right, value);
//    }
//    return node;
//}
//
//void inorder(Node* node) {
//    if (node != NULL) {
//        inorder(node->left);
//        cout << node->data << " ";
//        inorder(node->right);
//    }
//}
//
//void preorder(Node* node) {
//    if (node != NULL) {
//        cout << node->data << " ";
//        preorder(node->left);
//        preorder(node->right);
//    }
//}
//
//void postorder(Node* node) {
//    if (node != NULL) {
//        postorder(node->left);
//        postorder(node->right);
//        cout << node->data << " ";
//    }
//}
//
//int main() {
//    Node* root = NULL;
//    root = insert(root, 50);
//    root = insert(root, 30);
//    root = insert(root, 20);
//    root = insert(root, 40);
//    root = insert(root, 70);
//    root = insert(root, 60);
//    root = insert(root, 80);
//
//    cout << "Inorder traversal: ";
//    inorder(root);
//    cout << endl;
//
//    cout << "Preorder traversal: ";
//    preorder(root);
//    cout << endl;
//
//    cout << "Postorder traversal: ";
//    postorder(root);
//    cout << endl;
//
//    return 0;
//}


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() { root = NULL; }

    int getHeight(Node* node) {
        if (node == NULL) return 0;
        return node->height;
    }

    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getHeight(node->left) - getHeight(node->right);

        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* rightRotate(Node* node) {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));
        return temp;
    }

    Node* leftRotate(Node* node) {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));
        return temp;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
};

int main() {
    AVLTree tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}

