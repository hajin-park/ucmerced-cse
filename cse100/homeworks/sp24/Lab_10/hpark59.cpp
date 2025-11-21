#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;
};

struct MinHeap {
    int size;
    int capacity;
    Node** array;
};

Node* newNode(char data, int freq) {
    Node* temp = new Node();
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = new MinHeap();
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = new Node*[minHeap->capacity];
    return minHeap;
}

void swapNode(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

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

Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

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