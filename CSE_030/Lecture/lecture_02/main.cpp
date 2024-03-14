#include <iostream>
#include <string>
#include "WordleHelper.h"

using namespace std;

int main(){

    WordleHelper wh;
    wh.addGreen("_rite");
    wh.addYellow("_____");
    wh.addGray("slamoundbng");

    vector<string> result = wh.possibleSolutions();

    for (string& word : result){
        cout << word << endl;
    }

    return 0;

}