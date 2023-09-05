#include "BST.h"
#include <vector>

BST::BST() { 
    root = nullptr;
    numElements = 0;
}

void helper(BST::Node* curr) {
    if (curr == nullptr) {
        return;
    }
    helper(curr->leftChild);
    helper(curr->rightChild);
    delete curr;
    curr = nullptr;
}

BST::~BST() {
    clear();
    numElements = 0;
}

unsigned int BST::size() const {
    return numElements;
}

void BST::clear() {
    if (root == nullptr) {
        numElements = 0;
    }
    else {
        helper(root);
        root = nullptr;
        numElements = 0;
    }
}

bool BST::insert(int element) {
    Node* newNode = new Node(element);
    if(root == nullptr) {
        root = newNode;
        numElements++;
        return true;
    }
    Node* curr = root;
    while (curr->data != element) {
        if (element < curr->data) {
            if (curr->leftChild == nullptr) {
                curr->leftChild = newNode;
                newNode->parent = curr;
                numElements++;
                return true;
            } 
            else {
                curr = curr->leftChild;
            }
        }
        else if (element > curr->data) {
            if (curr->rightChild == nullptr) {
                curr->rightChild = newNode;
                newNode->parent = curr;
                numElements++;
                return true;
            } 
            else {
                curr = curr->rightChild;
            }
        }
    } 
    delete newNode;
    return false;
}

bool BST::find(const int & query) const {
    if(root == nullptr) {
        return false;
    }
    Node* curr = root;
    while (curr!=nullptr) {
        if (query < curr->data) {
            curr = curr->leftChild;
        }
        else if (query > curr->data) {
            curr = curr->rightChild;
        }
        else 
            return true;
    }
    return false;
}

BST::Node* BST::getLeftMostNode() {
    Node* curr = root;
    if (root == nullptr) {
        return nullptr;
    }
    while (curr->leftChild != nullptr) {
        curr = curr->leftChild;
    }
    return curr;
}

BST::Node* BST::Node::successor() {
    Node* curr = this;
    if (this->rightChild != nullptr) {
        curr = this->rightChild;
        while (curr->leftChild != nullptr) {
            curr = curr->leftChild;
        }
        return curr;
    }
    else {
        curr = this;
        if (curr->parent == nullptr) {
            return nullptr;
        }
        while (curr->parent != nullptr) {
            if (curr == curr->parent->leftChild) {
                return curr->parent;
            }
            else {
                curr = curr->parent;
            }
        }
        return nullptr;
    }
}
