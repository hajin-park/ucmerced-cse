#include <iostream>
#include "TimeSupport.h"
#include "RandomSupport.h"
#include "BinarySearchTree.h"

using namespace std;

// Do not modify the contents of this file

int main(){

    BinarySearchTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(1);
    tree.insert(7);

    tree.draw();

    BinarySearchTree backup = tree;
    tree.insert(8);

    tree.draw();
    backup.draw();

    backup.remove(backup.search(5));
    
    backup.draw();

    backup.remove(backup.search(7));

    backup.draw();

    return 0;
}