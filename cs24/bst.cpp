#include <iostream>
using namespace std;

class BST {
public:
    BST();
    ~BST();
    BST(const BST& source);
    // void search();
    // void insert();
    // int min();
    // int max();

private:
    struct Node {
        int data;
        Node* parent;
        Node* left;
        Node* right;
    };
    Node* root;
};

int main() {
    return 0;
}
