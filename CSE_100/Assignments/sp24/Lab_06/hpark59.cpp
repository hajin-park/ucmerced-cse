#include <iostream>

using namespace std;

class record{
  public:
    int key[11];

  record()
  {
    for(int i=1;i<=10;i++)
    key[i] = 0;
  }
};

// Global variables that can be accessed anywhere. Not recommend for serious programming. 
record* A;
int* C; 
record* B;
int k = 4;
int arraySize;


//CountSort using global variables instead of n and k:
void CountSort(int r) {
  // Create a new array to store the sorted sequence
  B = new record[arraySize+1];
  C = new int[11];
  // Initialize the count array
  for(int i=0;i<=10;i++)
    C[i] = 0;

  // Count the number of occurrences of each key
  for(int j=1;j<=arraySize;j++)
    C[A[j].key[r]] = C[A[j].key[r]] + 1;

  // Update the count array to show the position of each key
  for(int i=1;i<=10;i++)
    C[i] = C[i] + C[i-1];

  // Build the sorted sequence
  for(int j=arraySize;j>=1;j--) {
    B[C[A[j].key[r]]] = A[j];
    C[A[j].key[r]] = C[A[j].key[r]] - 1;
  }

  // Copy the sorted sequence back to the original sequence
  for(int j=1;j<=arraySize;j++)
    A[j] = B[j];

  // Free allocated space
  delete[] B;
  delete[] C;
}


void RadixSort() {
  // Perform counting sort for each digit
  for(int i=10;i>=1;i--)
    CountSort(i);
}

int main(int argc,char **argv) {

  // Get the size of the sequence
  cin >> arraySize;

  A = new record[arraySize+1];

  // Continue reading sequences until there is no more
  for(int i=1;i<=arraySize;i++)
  {
    for(int j=1;j<=10;j++)
    {
       cin >> A[i].key[j];
    }
  } 
  
  // Radix Sort: TBD
  RadixSort();
 
  //output 
  for(int i=1;i<=arraySize;i++)
  {
    for(int j=1;j<=10;j++)
       cout << A[i].key[j] << ";";
    cout << endl;
  } 


   // Free allocated space
  delete[] A;

  return 1;
}