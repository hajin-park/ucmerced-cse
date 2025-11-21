#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int key;
  Node* next;
};

void ListPrepend(Node*& head, int key) {
  Node* newNode = new Node;
  newNode->key = key;
  newNode->next = head;
  head = newNode;
}

void ListDelete(Node*& head, int key) {
  Node* current = head;
  Node* previous = NULL;
  while (current != NULL && current->key != key) {
    previous = current;
    current = current->next;
  }
  if (current != NULL) {
    if (previous != NULL) {
      previous->next = current->next;
    } else {
      head = current->next;
    }
    delete current;
  }
}

Node* ListSearch(Node* head, int key) {
  Node* current = head;
  while (current != NULL && current->key != key) {
    current = current->next;
  }
  return current;
}

int Hash(int key, int hashSize) {
  return key % hashSize;
}

void ChainedHashInsert(vector<Node*>& table, int key, int hashSize) {
  int index = Hash(key, hashSize);
  ListPrepend(table[index], key);
}

void ChainedHashDelete(vector<Node*>& table, int key, int hashSize) {
  int index = Hash(key, hashSize);
  Node* node = ListSearch(table[index], key);
  if (node != NULL) {
    ListDelete(table[index], key);
    cout << key << ":DELETED;" << endl;
  } else {
    cout << key << ":DELETE_FAILED;" << endl;
  }
}

Node* ChainedHashSearch(vector<Node*>& table, int key, int hashSize) {
  int index = Hash(key, hashSize);
  return ListSearch(table[index], key);
}

int main(int argc, char const *argv[]) {
  int number =  0;
  int hashSize = 0;
  bool repeat = true;

  string input = "";
  cin >> hashSize;

  vector<Node*> table(hashSize, NULL);

  do{
      number = 0;
      cin >> input;
      //Create integer if required by function
      if (input[0] != 'o' || input[0] != 'e'){
        for (int i = 1; i < input.size(); i++){
          int digit = input[i] - '0';
          number = 10 * number + digit;
        }
      }

      if(input[0] == 'i') {
        ChainedHashInsert(table, number, hashSize);
      } else if(input[0] == 'd') {
        ChainedHashDelete(table, number, hashSize);
      } else if(input[0] == 's') {
        Node* node = ChainedHashSearch(table, number, hashSize);
        if (node != NULL) {
          int index = Hash(number, hashSize);
          int position = 0;
          Node* current = table[index];
          while (current != node) {
            position++;
            current = current->next;
          }
          cout << number << ":FOUND_AT" << index << "," << position << ";" << endl;
        } else {
          cout << number << ":NOT_FOUND;" << endl;
        }
      } else if(input[0] == 'o') {
          for (int i = 0; i < hashSize; i++){
          cout << i << ":";
          Node* current = table[i];
          while (current != NULL) {
            cout << current->key << "->";
            current = current->next;
          }
          cout << ";" << endl;
        }
      } else if(input[0] == 'e'){
        repeat = false;
      } else {
        cout << "Wrong input" << endl;
      }
  } while(repeat);

  return 0;
}