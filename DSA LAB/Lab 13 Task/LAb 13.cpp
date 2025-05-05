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
//class Tree {
//public:
//    Node* root;
//
//    Tree() { root = NULL; }
//
//    void insert(int value) {
//        root = insertRec(root, value);
//    }
//
//    Node* insertRec(Node* node, int value) {
//        if (node == NULL) {
//            node = new Node(value);
//            return node;
//        }
//
//        if (value < node->data) {
//            node->left = insertRec(node->left, value);
//        } else if (value > node->data) {
//            node->right = insertRec(node->right, value);
//        }
//
//        return node;
//    }
//
//    void DFS(Node* node) {
//        if (node == NULL) return;
//
//        cout << node->data << " "; 
//        DFS(node->left);
//      
//        DFS(node->right);
//       
//    }
//};
//
//int main() {
//    Tree tree;
//    tree.insert(8);
//    tree.insert(3);
//    tree.insert(10);
//    tree.insert(1);
//    tree.insert(6);
//    tree.insert(14);
//    tree.insert(4);
//    tree.insert(7);
//    tree.insert(13);
//
//    cout << "DFS traversal: ";
//    tree.DFS(tree.root);
//    cout << endl;
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Graph {
//    int V;
//    vector<vector<int>> adj;
//
//public:
//    Graph(int vertices) {
//        V = vertices;
//        adj.resize(V);
//    }
//
//    void addEdge(int u, int v) {
//        adj[u].push_back(v);
//    }
//
//    void DFS(int vertex) {
//        vector<bool> visited(V, false);
//        DFSUtil(vertex, visited);
//    }
//
//    void DFSUtil(int vertex, vector<bool>& visited) {
//        visited[vertex] = true;
//        cout << vertex << " ";
//
//        for (int adjVertex : adj[vertex]) {
//            if (!visited[adjVertex]) {
//                DFSUtil(adjVertex, visited);
//            }
//        }
//    }
//};
//
//int main() {
//    Graph graph(5);
//    graph.addEdge(0, 1);
//    graph.addEdge(0, 2);
//    graph.addEdge(1, 3);
//    graph.addEdge(1, 4);
//
//    cout << "DFS traversal: ";
//    graph.DFS(0);
//    cout << endl;
//
//    return 0;
//}




//
//
//#include <iostream>
//#include <queue>
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
//class Tree {
//public:
//    Node* root;
//
//    Tree() { root = NULL; }
//
//    void BFS() {
//        if (root == NULL) return;
//
//        queue<Node*> q;
//        q.push(root);
//
//        while (!q.empty()) {
//            Node* node = q.front();
//            q.pop();
//            cout << node->data << " ";
//
//            if (node->left != NULL) q.push(node->left);
//            if (node->right != NULL) q.push(node->right);
//        }
//    }
//};
//
//int main() {
//    Tree tree;
//    tree.root = new Node(1);
//    tree.root->left = new Node(2);
//    tree.root->right = new Node(3);
//    tree.root->left->left = new Node(4);
//    tree.root->left->right = new Node(5);
//
//    cout << "BFS traversal: ";
//    tree.BFS();
//    cout << endl;
//
//    return 0;
//}




#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V;
vector<vector<int>> adj;
vector<bool> visited;

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

void BFS(int vertex) {
    queue<int> q;

    visited[vertex] = true;
    q.push(vertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";

        for (int adjVertex : adj[currentVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                q.push(adjVertex);
            }
        }
    }
}

int main() {
    V = 5;
    adj.resize(V);
    visited.resize(V, false);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    cout << "BFS traversal: ";
    BFS(0);
    cout << endl;

    return 0;
}


