#include <iostream>
#include <ostream>
#include <stdexcept>
#include <chrono>

using namespace std;


// ===============================================================
// WE HAVE TO MANUALLY PLACE ALL OF THE DATA STRUCTURE CODE IN HERE
// ===============================================================

template <class T>
struct Node{
    T data;
    Node* next;

    Node(T value){
        data = value;
        next = nullptr;
    }

    bool operator==(const Node& other){
        return data == other.data;
    }
};

template <class T>
struct LinkedList{
    Node<T>* head;             // Keep a pointer to the head (first element) of the list

    LinkedList(){       
        head = nullptr;     // A null pointer for head means the list is empty
    }

    void prepend(T value){
        if (head == nullptr){           // If we currently have an empty list
            head = new Node<T>(value);     // Create a new node with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Node<T>* temp = new Node<T>(value);   // Make a new node with the given value
            temp->next = head;              // Make the current head to be the next element of the newly created node
            head = temp;                    // Point the head to the newly created node
        }
    }

    void append(T value){
        if (head == nullptr){               // If we have an empty list
            head = new Node<T>(value);         // Create a new node with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Node<T>* temp = new Node<T>(value);   // Make a new node with the given value

            Node<T>* last = head;              // Find the last element in the list
            while (last->next != nullptr){  // That is the first element whose next pointer is null
                last = last->next;
            }

            last->next = temp;              // Make the next pointer of the last element point to the newly created node
        }
    }

    bool search(T value){
        Node<T>* temp = head;
        
        while (temp != nullptr){
            if (temp->data == value){
                return true;
            }
            temp = temp->next;
        }
        
        return false;
    }

    ~LinkedList(){                  // We must release all the memory we are occupying, which is not necessarily one contiguous chunk
        Node<T>* temp = head;          // Start at the head
        while (head != nullptr){    // As long as there are more elements
            head = head->next;      // release the head element and make its pointer point to the next element
            delete temp;
            temp = head;
        }
    }
};

template <class T>
std::ostream& operator<< (std::ostream& os, LinkedList<T>& list){ // Print out the list on one line, separating elements by a space
    Node<T>* current = list.head;
    while (current != nullptr){
        os << current->data << " ";
        current = current->next;
    }

    return os;
}


template <class T>
struct ArrayList{
    T* data;
    int capacity;
    int count;

// Helper functions

    bool linear_search(const T& value){
        for (int i = 0; i < count; i++){
            if (data[i] == value){
                return true;
            }
        }
        return false;
    }

    bool binary_search(const T& value){
        int left = 0;
        int right = count;

        while (left <= right){
            int mid = (left + right) / 2;
            if (data[mid] == value){
                return true;
            }
            else if (data[mid] > value){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return false;
    }


    void selection_sort(){
        for (int i = 0; i < count; i++){
            T minVal = data[i];
            int minPos = i;
            for(int j = i; j < count; j++){
                if (data[j] < minVal){
                    minVal = data[j];
                    minPos = j;
                }
            }
            T temp = data[i];
            data[i] = data[minPos];
            data[minPos] = temp;
        }
    }

    void insertion_sort(){
        for (int i = 1; i < count; i++){
            int j = i;
            while (j > 0 && data[j-1] > data[j]){
                T temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
                j--;
            }
        }
    }


    // ================== START QUICKSORT ==================

    int partition(int start, int end){
        T pivot = data[start];

        int count = 0;
        for (int i = start+1; i <= end; i++){
            if (data[i] <= pivot){
                count++;
            }
        }

        int pivotIndex = start + count;

        T temp = data[start];
        data[start] = data[pivotIndex];
        data[pivotIndex] = temp;


        int left = start;
        int right = end;

        while (left < pivotIndex && right > pivotIndex){
            while(data[left] <= data[pivotIndex]){
                left++;
            }
            while (data[right] >= data[pivotIndex]){
                right--;
            }
            if (left < pivotIndex && right > pivotIndex){
                T temp = data[left];
                data[left] = data[right];
                data[right] = temp;
            }

        }
        return pivotIndex;
    }
 
    void quickSort(int start, int end) {
        if (start >= end)
            return;
    
        int p = partition(start, end);

        quickSort(start, p - 1);
    
        quickSort(p + 1, end);
    }

    void quick_sort(){
        quickSort(0, count - 1);
    }

    // =================== END QUICKSORT ===================
                    
public:
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }

    void append(T value){
        data[count] = value;
        count++;

        if (count == capacity){

            int oldCapacity = capacity;
            capacity *= 2;

            T* temp = new T[capacity];

            for (int i = 0; i < oldCapacity; i++){
                temp[i] = data[i];
            }

            T* oldLocation = data;
            data = temp;
            delete[] oldLocation;
        }
    }

    void add(T value){
        append(value);
        insertion_sort();
    }

    int size() const{
        return count;
    }

    T& operator[](int index){
        return data[index];
    }

    T& get(int index) const{
        return data[index];
    }

    bool search(const T& value){
        return linear_search(value);
    }

    void sort(){
        insertion_sort();
    }

    ~ArrayList(){
        delete[] data;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, ArrayList<T>& list){
    for (int i = 0; i < list.size(); i++){
        os << list[i] << " ";
    }

    return os;
}


typedef enum {
    sec,
    mill
} Unit;

typedef std::chrono::time_point<std::chrono::high_resolution_clock> timestamp;

int time_diff(timestamp start, timestamp end, Unit u = mill){
    
    if (u == mill){
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
        
        return (int) diff;
    }
    else{
        auto diff = std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
        
        return (int) diff;
    }
}


timestamp current_time(){
    return std::chrono::high_resolution_clock::now();
}

// ===============================================================
// WE HAVE TO MANUALLY PLACE ALL OF THE DATA STRUCTURE CODE IN HERE
// ===============================================================


string reverse(string& word){
    string result = "";

    for (int i = word.length()-1; i >= 0; i--){
        result += word[i];
    }

    return result;
}

int hash_value(string word) {
    int hash = 0;

    for (int i = 0; i < word.length(); i++) {
        hash += (int) word[i];
    }

    return hash;
}

int f(string word){
    if (word.length() == 1){
        word += "zz";
    } else if (word.length() == 2) {
        word += "z";
    }

    int pos = word[0] - 97;
    if (pos < 0 || pos > 25){
        pos = 0;
    }

    int pos1 = word[1] - 97;
    if (pos1 < 0 || pos1 > 25){
        pos1 = 0;
    }

    int pos2 = word[2] - 97;
    if (pos2 < 0 || pos2 > 25){
        pos2 = 0;
    }

    return pos + pos1*26 + pos2*26*26;
}

int main() {
    ArrayList<LinkedList<string>> ht;
    ArrayList<string> words;

    for (int i = 0; i < 26*26*26; i++){
        LinkedList<string> bucket;
        ht.append(bucket);
    }

    string word;
    while (getline(cin, word)){
        int pos = f(word);
        ht[pos].append(word);
        words.append(word);
    }

    timestamp start = current_time();

    int count = 0;
    for (int i = 0; i < words.size(); i++){
        string current = words[i];
        string inverse = reverse(current);

        int pos = f(inverse);

        if (ht[pos].search(inverse)){
            count++;
        }
    }

    timestamp end = current_time();

    cout << "Count: "<<  count << endl;
    cout << "Duration: " << time_diff(start, end) << endl;

    return 0;
}