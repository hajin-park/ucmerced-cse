#include <iostream>
#include <ArrayList.h>
#include <TimeSupport.h>

using namespace std;

string reverse(string& word){
    string result = "";

    for (int i = word.length()-1; i >= 0; i--){
        result += word[i];
    }

    return result;
}

int f(string word){
    if (word.length() == 1){
        word += 'z';
    }
    int pos = word[0] - 97;
    if (pos < 0 || pos > 25){
        pos = 0;
    }

    int pos1 = word[1] - 97;
    if (pos1 < 0 || pos1 > 25){
        pos1 = 0;
    }


    return pos + pos1*26;
}


int main(){

    ArrayList<ArrayList<string>> ht;
    ArrayList<string> words;

    for (int i = 0; i < 26*26; i++){
        ht.append(ArrayList<string>());
    }

    string word;
    while (getline(cin, word)){
        words.append(word);
        int pos = f(word);
        ht[pos].append(word);
    }

    TimeStamp start;

    int count = 0;
    for (int i = 0; i < words.size(); i++){
        string current = words[i];
        string inverse = reverse(current);

        int pos = f(inverse);

        if (ht[pos].search(inverse)){
            count++;
        }
    }

    TimeStamp end;

    cout << "Count: "<<  count << endl;
    cout << "Duration: " << end - start << endl;

    return 0;
}