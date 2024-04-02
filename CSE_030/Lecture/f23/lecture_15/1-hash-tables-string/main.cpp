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

int f(string s){
    if (s.length() < 4){
        for (int i = 0; i < 4-s.length(); i++){
            s += 'z';
        }
    }
    int one = s[0] - 97;
    int two = s[1] - 97;
    int three = s[2] - 97;
    int four = s[3] - 97;
    
    if (one < 0 || one > 25){
        one = 0;
    }
    if (two < 0 || two > 25){
        two = 0;
    }
    if (three < 0 || three > 25){
        three = 0;
    }
    if (four < 0 || four > 25){
        four = 0;
    }

    return one + two*26 + three*26*26 + four * 26*26*26;
}

int main(){

    ArrayList<string> words;
    ArrayList<ArrayList<string>> ht;
    for (int i = 0; i < 26*26*26*26; i++){
        ht.append(ArrayList<string>());
    }

    string word;
    while (getline(cin, word)){
        int pos = f(word);
        ht[pos].append(word);
        words.append(word);
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