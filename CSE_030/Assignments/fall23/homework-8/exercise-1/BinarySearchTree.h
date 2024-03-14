#ifndef BST_H
#define BST_H
#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree{
    Node* root;

    Node* insert_helper(int x, Node* root) {
        if (root == nullptr) {
            // Attach to empty tree OR leaf node
            root = new Node(x);
        } else {
            if (x < root->data) {
                root->left = insert_helper(x, root->left);
            } else {
                root->right = insert_helper(x, root->right);
            }
        }
        return root;
    }

    Node* search_helper(int x, Node* root) {
        // Node does not exist or match is found
        if (root == nullptr || root->data == x) return root;
        // Traverse down by value
        (x < root->data) ? search_helper(x, root->left) : search_helper(x, root->right);
    }

    Node* min_helper(Node* node) {
        if (node == nullptr) {
            throw std::logic_error("Tree is empty.");
        }
        // Traverse down leftmost path
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* max_helper(Node* node) {
        if (node == nullptr) {
            throw std::logic_error("Tree is empty.");
        }
        // Travel down rightmost path
        Node* current = node;
        while (current && current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

    void copy_helper(Node*& thisRoot, Node* otherRoot) {
    if (otherRoot == nullptr) {
        // Tree is empty
        thisRoot = nullptr;
    } else {
        // Deep copy all nodes
        thisRoot = new Node(otherRoot->data);
        copy_helper(thisRoot->left, otherRoot->left);
        copy_helper(thisRoot->right, otherRoot->right);
    }
}

public:
    BinarySearchTree() {
        root = nullptr;
    }

    BinarySearchTree(const BinarySearchTree& other) {
        root = nullptr;
        copy_helper(root, other.root);
    }

    void insert(int x) {
        root = insert_helper(x, root);
    }

    void traverse(Node* root) {
        if (root != nullptr) {
            traverse(root->left);
            std::cout << root->data;
            traverse(root->right);
        }
    }

    Node* search(int x) {
        return search_helper(x, root);
    }

    Node* min() {
        return min_helper(root);
    }

    Node* max() {
        return max_helper(root);
    }

    Node* successor(Node* start) {
        if (start == nullptr) {
            // Empty tree or leaf node
            return nullptr;
        }
        
        if (start->right != nullptr) {
            // Right node exists, find successor (next largest node)
            return min_helper(start->right);
        } else {
            // Right node does not exist, find predecessor (next smallest node)
            Node* parent = findParent(start);
            if (parent == nullptr) {
                return nullptr;
            } else {
                return start == parent->left ? parent : nullptr;
            }
        }
    }

    Node* findParent(Node* start) {
        if (start == root) {
            return nullptr;
        }

        Node* parent = root;
        Node* temp = root;

        while(start->data != temp->data) {
            parent = temp;
            temp = (start->data < temp->data) ? temp->left : temp->right;
        }
        
        return parent;
    }

    void remove(Node* node) {
        if (node == nullptr) {
            return;
        }

        // Node has both children, swap node value with its successor value, remove successor node
        if (node->left != nullptr && node->right != nullptr) {
            Node* succ = successor(node);
            node->data = succ->data;
            remove(succ);
            return;
        }

        Node* parent = findParent(node);
        Node* child = node->left ? node->left : node->right;

        if (parent == nullptr) {
            // Node is the root
            root = child;
        } else {
            // Attach the child to the correct side of the parent
            if (parent->left == node) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }

        delete node;
    }


    // A function to display the tree graphically
    void displayTree(Node* r, int level, int direction){
        // Don't worry about this function, just use it
        if (r != NULL){
            displayTree(r->right, level+1, 1);
            
            for (int i = 0; i < level-1; i++) {
                std::cout << "   ";
            }
            if (level > 0 ){
                if (direction == 1){
                    std::cout << " /--";
                }
                else{
                    std::cout << " \\--";
                }
            }
            std::cout << r->data;
            std::cout << std::endl;
            level++;
            
            displayTree(r->left, level, -1);
        }
    }

    // Call the function to display the tree and leave some space afterwards
    void draw(){
        displayTree(root, 0, 0);
        std::cout << std::endl << std::endl;
    }

};

#endif