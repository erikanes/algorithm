#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node(int d) : d_(d), left_(nullptr), right_(nullptr) {}
    ~Node() { delete left_; delete right_; }

    int d_;
    Node* left_;
    Node* right_;
};

class BST {
public:
    BST() : root_(nullptr) {}
    ~BST() { delete root_; }
    void add(Node* _node) {
        if (!root_) { root_ = _node; return; }

        Node* n = root_;
        while (n) {
            if (_node->d_ < n->d_) {
                if (!n->left_) { n->left_ = _node; return; }
                else n = n->left_;
            }
            else {
                if (!n->right_) { n->right_ = _node; return; }
                else n = n->right_;
            }
        }
    }

    void post_order(Node* _node) {
        if (!_node) return;

        post_order(_node->left_);
        post_order(_node->right_);
        cout << _node->d_ << '\n';
    }

    Node* root_;
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    BST bst;
    int n;
    while (cin >> n) bst.add(new Node(n));
    
    bst.post_order(bst.root_);
    
    return 0;
}