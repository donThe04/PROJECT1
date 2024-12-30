#include <iostream>
#include <vector>
#include <map>

using namespace std;

// C?u tr�c n�t c?a c�y
struct Node {
    int id;
    vector<Node*> children;
    Node(int id) : id(id) {}
};

// T?o ra l?p Tree
class Tree {
public:
    map<int, Node*> nodes; // �? luu t?t c? c�c n�t trong c�y
    Node* root = nullptr;  // Con tr? d?n n�t g?c

    // T?o n�t g?c
    void makeRoot(int id) {
        if (nodes.find(id) == nodes.end()) {
            root = new Node(id);
            nodes[id] = root;
        }
    }

    // Th�m n�t u l�m con c?a n�t v
    void insert(int u, int v) {
        if (nodes.find(u) != nodes.end() || nodes.find(v) == nodes.end()) {
            return; // N?u n�t u d� t?n t?i ho?c n�t v kh�ng t?n t?i th� b? qua
        }
        Node* parent = nodes[v];
        Node* newNode = new Node(u);
        parent->children.push_back(newNode);
        nodes[u] = newNode;
    }

    // Duy?t PreOrder
    void preOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->id << " ";
        for (auto child : node->children) {
            preOrder(child);
        }
    }

    // Duy?t InOrder (ch? ho?t d?ng t?t v?i c�y nh? ph�n)
    void inOrder(Node* node) {
        if (node == nullptr) return;
        if (!node->children.empty()) {
            inOrder(node->children[0]); // Duy?t con tr�i
        }
        cout << node->id << " "; // In n�t hi?n t?i
        for (int i = 1; i < node->children.size(); i++) {
            inOrder(node->children[i]); // Duy?t con ph?i (v� c�c con ti?p theo n?u c�)
        }
    }

    // Duy?t PostOrder
    void postOrder(Node* node) {
        if (node == nullptr) return;
        for (auto child : node->children) {
            postOrder(child);
        }
        cout << node->id << " ";
    }
};

int main() {
    Tree tree;
    string command;
    
    while (cin >> command) {
        if (command == "*") break; // K?t th�c d? li?u
        
        if (command == "MakeRoot") {
            int u;
            cin >> u;
            tree.makeRoot(u);
        } else if (command == "Insert") {
            int u, v;
            cin >> u >> v;
            tree.insert(u, v);
        } else if (command == "PreOrder") {
            tree.preOrder(tree.root);
            cout << endl;
        } else if (command == "InOrder") {
            tree.inOrder(tree.root);
            cout << endl;
        } else if (command == "PostOrder") {
            tree.postOrder(tree.root);
            cout << endl;
        }
    }

    return 0;
}

