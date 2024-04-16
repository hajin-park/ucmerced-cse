#include <iostream>
#include <string>

using namespace std;

// The input consists of 6 integers, one per each line. Each
// integer represents the frequency of characters, A, B, C, D, E, and F, in this order. The test cases
// have been built so that while building trees it never happens that the same frequency appears
// twice. Then, the decision about which tree goes to the left and which one goes to the right is
// always straightforward, and the final tree should be unique.


// Create a Huffman Code algorithm using a min-heap
// Finally, print the Huffman Code starting from A to F with its code, variable length.

// Create a struct for the node
struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;
};

// Create a struct for the min-heap
struct MinHeap {
    int size;
    int capacity;
    Node** array;
};

// Create a new node
Node* newNode(char data, int freq) {
    Node* temp = new Node();
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Create a new min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = new MinHeap();
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = new Node*[minHeap->capacity];
    return minHeap;
}

// Swap two nodes
void swapNode(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

// Heapify
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if the size of the heap is 1
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract the minimum node from the heap
Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node into the heap
void insertMinHeap(MinHeap* minHeap, Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Build the min-heap
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

// Check if the node is a leaf
int isLeaf(Node* root) {
    return !(root->left) && !(root->right);
}

// Create a min-heap and build the tree
Node* buildHuffmanTree(char data[], int freq[], int size) {
    Node *left, *right, *top;
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        insertMinHeap(minHeap, newNode(data[i], freq[i]));
    }
    buildMinHeap(minHeap);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void createHuffmanCodeStrings(Node* root, int tree[], int top, string outputs[]) {
    if (root->left) {
        tree[top] = 0;
        createHuffmanCodeStrings(root->left, tree, top + 1, outputs);
    }
    if (root->right) {
        tree[top] = 1;
        createHuffmanCodeStrings(root->right, tree, top + 1, outputs);
    }
    if (isLeaf(root)) {
        int char_position = root->data - 'A';
        for (int i = 0; i < top; i++) {
            outputs[char_position] += to_string(tree[i]);
        }
    }
}

void printHuffmanCodeStrings(string outputs[]) {
    for (int i = 0; i < 6; i++) {
        cout << outputs[i] << "\n";
    }

}

// Main function
int main(int argc, char** argv) {
    int size = 6;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    string outputs[] = {"A:", "B:", "C:", "D:", "E:", "F:"};
    Node* root = buildHuffmanTree(data, arr, size);
    int tree[100], top = 0;
    createHuffmanCodeStrings(root, tree, top, outputs);
    printHuffmanCodeStrings(outputs);
    return 0;
}