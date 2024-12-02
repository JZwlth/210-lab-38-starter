#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"

using namespace std;

void displayMenu();
void processChoice(IntBinaryTree &tree);

int main() {

    void displayMenu() {
    cout << "\nMenu Options:" << endl;
    cout << "1. Add a code" << endl;
    cout << "2. Delete a code" << endl;
    cout << "3. S;
    cout << "Enter your choice: ";
}

void processChoice(IntBinaryTree &tree) {
    int choice;
    string code;
    string newCode;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline character after integer input

        switch (choice) {
            case 1:
                cout << "Enter code to add: ";
                getline(cin, code);
                tree.insertNode(code);
                cout << "Code added." << endl;
                break;
            case 2:
                cout << "Enter code to delete: ";
                getline(cin, code);
                if (tree.searchNode(code)) {
                    tree.remove(code);
                    cout << "Code deleted." << endl;
                } else {
                    cout << "Code not found." << endl;
                }
                break;
            case 3:
                cout << "Enter code to search: ";
                getline(cin, code);

    return 0;
};