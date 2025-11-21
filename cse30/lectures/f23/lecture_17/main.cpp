#include <iostream>
#include <TimeSupport.h>
#include <RandomSupport.h>

using namespace std;


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

    Node* insert_helper(Node* root, int value){
        if (root == nullptr){
            root = new Node(value);
        }
        else{
            if (value < root->data){
                root->left = insert_helper(root->left, value);
            }
            else{
                root->right = insert_helper(root->right, value);
            }
        }

        return root;
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

    Node* search_helper(Node* root, int value){
        if (root == nullptr){
            return nullptr;
        }
        else{
            if (root->data == value){
                return root;
            }
            else if (value < root->data){
                return search_helper(root->left, value);
            }
            else{
                return search_helper(root->right, value);
            }
        }
    }

    Node* min_helper(Node* r){
        if(r == nullptr){
            return nullptr;
        }
        else if(r->left == nullptr){
            return r;
        }
        else{
            return min_helper(r->left);
        }
    }

public:
    BinarySearchTree(){
        root = nullptr;
    }

    void insert(int x){
        root = insert_helper(root, x);
    }

    // Call the function to display the tree and leave some space afterwards
    void draw(){
        displayTree(root, 0, 0);
        std::cout << std::endl << std::endl;
    }

    Node* search(int value){
        return search_helper(root, value);
    }

    Node* findParent(Node* p){
        if (p == root){
            return nullptr;
        }
        Node* temp = root;
        Node* parent = root;

        while(temp != p){
            parent = temp;
            if (p->data < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }

        return parent;
    }

    Node* successor(Node* start){
        if (start == nullptr){
            return nullptr;
        }
        if (start->right != nullptr){
            return min_helper(start->right);
        }
        else {
            Node* parent = findParent(start);
            if (parent == nullptr){
                return nullptr;
            }
            else{
                if (start == parent->left){
                    return parent;
                }
                else {
                    return nullptr;
                }
            }
        }
    }

    void remove(Node* p){
        if (p->left != nullptr && p->right != nullptr){
            // P is pointing to a node that has
            // both a left and a right child

            Node* succ = successor(p);
            p->data = succ->data;
            remove(succ);
        }
        
        if (p->left == nullptr && p->right == nullptr){
            Node* parent = findParent(p);
            if (parent->left == p){
                parent->left = nullptr;
            }
            else if(parent->right == p){
                parent->right = nullptr;
            }
            delete p;
        }

        if (p->left == nullptr && p->right != nullptr){
            // We have a right child but not a left
            // handle this
        }

        if (p->left != nullptr && p->right == nullptr){
            // We have a left child but not a right
            // handle this
        }
    }

    Node* min(){
        return min_helper(root);
    }
};

int main(){

    BinarySearchTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.draw();

    tree.remove(tree.search(5));

    tree.draw();
   
    return 0;
}