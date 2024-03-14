#ifndef STASH_H
#define STASH_H

#include <stdexcept>
#include <string>
#include "Stack.h"


// Your code here
class Stash {
    int balance = 0;
    Stack<int> actions;

    public:
        void deposit(int amount) {
            if (amount >= 0) {
                balance += amount;
                actions.push(-amount);
            }
        }

        void withdraw(int amount) {
            if (balance - amount >= 0 && amount >= 0) {
                balance -= amount;
                actions.push(amount);
            }
        }

        void undo() {
            int undo_amount = actions.pop();
            balance += undo_amount;
        }

        int getBalance() {
            return balance;
        }
};

#endif