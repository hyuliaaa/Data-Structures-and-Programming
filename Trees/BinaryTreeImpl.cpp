#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree{
    Node<T>* root;


    void insert(T key);
    void deleteTree();
    Node<T>* copyNodes(Node<T>* node);
public:
    BinaryTree();
    BinaryTree(const BinaryTree<T>& other);
    BinaryTree<T>& operator=(BinaryTree<T>& other);
    ~BinaryTree();
};

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &other) {
    copyNodes(other);
}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T> &other) {
    if(this!=&other) {
        deleteTree();
        root=copyNodes(other.root);
    }

    return *this;
}

template<typename T>
BinaryTree<T>::BinaryTree():root(nullptr){}

template<typename T>
Node<T>* BinaryTree<T>::copyNodes(Node<T> *node) {
    if(node == nullptr) {
        return nullptr;
    }

    Node<T>* newNode = new Node(node->data);
    newNode->left = copyNodes(node->left);
    newNode->right = copyNodes(node->right);

    return newNode;
}

template<typename T>
void BinaryTree<T>::insert(T key) {
    if(root == nullptr) {
        root = new Node(key);
        return;
    }

    queue<Node<T>*> q;
    q.push(root);

    while (!q.empty()) {
        Node<T> *curr = q.front();
        q.pop();

        if(curr->left== nullptr) {
            curr->left = new Node(key);
            return;
        } else {
            q.push(curr->left);
        }

        if(curr->right == nullptr) {
            curr->right = new Node(key);
            return;
        } else {
            q.push(curr->right);
        }
    }
}
template<typename T>
void BinaryTree<T>::deleteTree() {
    if(root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
template<typename T>
BinaryTree<T>::~BinaryTree() {
    deleteTree();
}

int main() {


    return 0;
}
