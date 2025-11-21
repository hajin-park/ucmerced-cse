#include <iostream>
#include <stdexcept>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;


struct Person {
    string name;
    int time;
};

int main(){

    Queue<Person> line;

    int jobCount;
    cin >> jobCount;

    for (int i = 0; i < jobCount; i++){
        string name;
        int time;
        cin >> name;
        cin >> time;

        Person person = {name, time};
        line.enqueue(person);

        // cout << name << " : " << time << endl;
    }

    int period;
    cin >> period;

    // Output round robin schedule, where person can use machine for no longer than the set period
    while (!line.isEmpty()) {
        Person current_person = line.dequeue();
        int time = 0;

        // Remaining time exceeds period
        if (period - current_person.time <= 0) {
            time = period;

        // Remaining time is less than the period
        } else {
            time = current_person.time;
        }

        current_person.time -= period;

        // Enqueue current person if they have remaining time
        if (current_person.time > 0) {
            line.enqueue(current_person);
        }

        cout << current_person.name << " - " << time << endl;
    }


    cout << "Done..." << endl;

    return 0;
}