/*
    partb.cpp

    Author: Clayton Kramp

    Created: 10/10/2018

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#define WHITESPACE 15

using namespace std;

// Print out the menu nicely
void printout(map<string, int> menuWithPrices) {
    cout << "======================" << endl;
    cout << "=====    MENU   ======" << endl;
    cout << "======================" << endl;
    for (auto entry: menuWithPrices) {
        int whiteSpaceLength = WHITESPACE - entry.first.length();
        string blanks(whiteSpaceLength, ' ');
        cout << " | " << entry.first << blanks << entry.second << " | " << endl;
    }
    cout << "======================" << endl;

}

int main() {
    // Let's initialize our menu!
    map<string, int> menuWithPrices = {
        {"Burger", 3},
        {"Fries", 1},
        {"Sandwich", 5},
        {"Salad", 2},
        {"Soda", 1},
        {"Apple", 2}
    };
    // Let's add a few more items
    menuWithPrices["Sundae"] = 8;
    menuWithPrices["Hotdog"] = 2;
    menuWithPrices["Tacos"] = 4;

    string input;
    cout << "What would you like to order today? Please choose from our menu. Type quit to complete order" << endl;
    printout(menuWithPrices);
    // Let's read in what our customer wants
    cin >> input;
    int totalPrice = 0;
    // Let's continue to take in orders until they "quit"
    while(input != "quit" && input != "q") {
        if (menuWithPrices.count(input) > 0) {
            totalPrice += menuWithPrices[input];
        } else {
            cout << "Item not found in menu!" << endl;
        }
        cin >> input;
    }
    cout << "Your total order for today will be: $" << totalPrice << endl;

    return 0;
}
