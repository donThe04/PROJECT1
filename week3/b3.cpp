#include <iostream>
#include <vector>
#include <map>

using namespace std;

// C?u trúc nút c?a cây
struct Node {
    int id;
    vector<Node*> children;
    Node(int id) : id(id) {}
};

// T?o ra l?p Tree
class Tree {
public:
    map<int, Node*> nodes; // Ð? luu t?t c? các nút trong cây
    Node* root = nullptr;  // Con tr? d?n nút g?c

    // T?o nút g?c
    void makeRoot(int id) {
        if (nodes.find(id) == nodes.end()) {
            root = new Node(id);
            nodes[id] = root;
        }
    }

    // Thêm nút u làm con c?a nút v
    void insert(int u, int v) {
        if (nodes.find(u) != nodes.end() || nodes.find(v) == nodes.end()) {
            return; // N?u nút u dã t?n t?i ho?c nút v không t?n t?i thì b? qua
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

    // Duy?t InOrder (ch? ho?t d?ng t?t v?i cây nh? phân)
    void inOrder(Node* node) {
        if (node == nullptr) return;
        if (!node->children.empty()) {
            inOrder(node->children[0]); // Duy?t con trái
        }
        cout << node->id << " "; // In nút hi?n t?i
        for (int i = 1; i < node->children.size(); i++) {
            inOrder(node->children[i]); // Duy?t con ph?i (và các con ti?p theo n?u có)
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
        if (command == "*") break; // K?t thúc d? li?u
        
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

