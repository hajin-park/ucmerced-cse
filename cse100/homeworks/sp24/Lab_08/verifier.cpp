#include <iostream>

using namespace std;


int main(int argc,char **argv) {

  // Get the size of the sequence
  int n = 1;
  int* p; 

  cin >> n;

  p = new int[n+1];
  //read p; 
  p[0] = 0; 
  for(int i=1; i<=n; i++)
  {
    cin >> p[i];  
  }


 
 // for(int i=1; i<=n; i++)
 //   cout << p[i]<< endl;

  int total_length = 0; 
  int total_revenue = 0; 

  int student_claimed_revenue = 0; 
  int length = 0; 

  cin >> student_claimed_revenue;
  do{
    cin >> length; 
    if(length > 0)
    {
      total_length += length;
      total_revenue += p[length]; 
    }
  }while(length >0);

  //cout << total_length << endl;
  //cout << total_revenue << endl;
  
  int optimal_revenue;
  cin >> optimal_revenue; 

  if (student_claimed_revenue != total_revenue || total_revenue != optimal_revenue) 
    cout << 0 << endl;

   // Free allocated space
  delete[] p;

  return 1;
}
