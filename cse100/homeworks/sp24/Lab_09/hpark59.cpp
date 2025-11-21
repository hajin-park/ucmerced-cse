#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <ctime>

using namespace std;


// Global Variables
vector<vector<int> >m;
vector<vector<int> >s;
int size;


// Function Declaration
void MatrixChainOrder(int *);
void PrintOptimalParens(int, int);

 
int main(int argc,char **argv) { 
  int *p = NULL;
  // Get number of matrices in the input
  cin >> size;

    // We have one more dimension than matrices
    p = new int[size+1];

    // Read each dimension and store in array
    for(int i=0; i<size+1; i++)
      cin >> p[i];

    // Set up the our scratch vectors
    m.clear(); s.clear(); // Make sure that the vectors are empty
    m.resize(size); s.resize(size); // Set the number of rows

    for(int i=0; i<size; i++) {      
      m[i].resize(size);
      s[i].resize(size); // Set the number of columns
    }    

    // Compute matrix chain order through dynamic programming
    MatrixChainOrder(p);

    // Output Minimum Number of Computations
    cout << m[0][size-1] << endl;

    // Output Sequence
    PrintOptimalParens(0, size-1);
    cout << endl;

    // Remove allocated space
    delete [] p;
}


void MatrixChainOrder(int *p) {
// compute m[i][j] and s[i][j] using DP
    int n = size;
    for(int i=0; i<n; i++) {
        m[i][i] = 0;
    }
    
    for(int l=2; l<=n; l++) {
        for(int i=0; i<n-l+1; i++) {
        int j = i+l-1;
        m[i][j] = INT_MAX;
        for(int k=i; k<j; k++) {
            int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
            if(q < m[i][j]) {
            m[i][j] = q;
            s[i][j] = k;
            }
        }
        }
    }
}


void PrintOptimalParens(int i, int j) {
  if(i==j) {
    cout << "A" << i;  //key
  } else {
    cout << "(";
    PrintOptimalParens(i, s[i][j]);
    PrintOptimalParens(s[i][j]+1, j);
    cout << ")";
  }
}