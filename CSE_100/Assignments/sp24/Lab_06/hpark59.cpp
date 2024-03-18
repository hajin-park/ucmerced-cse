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


void CountSort(int r){  // r will be used to refer to key[r]
  // TBD

 

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