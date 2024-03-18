#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

  int number =  0;
  int hashSize = 0;
  bool repeat = true;

  string input = "";
  cin >> hashSize;

  //

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

      if(input[0] == 'i'){
       // ...
      }else if(input[0] == 'd'){
       // ...
      }else if(input[0] == 's'){
       // ...
      }else if(input[0] == 'o'){
       // ...
      }else if(input[0] == 'e'){
        repeat = false;
      }else{
        cout << "Wrong input" << endl;
      }
  }while(repeat);

  return 0;
}