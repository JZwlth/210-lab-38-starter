#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"

using namespace std;

void displayMenu();
void processChoice(IntBinaryTree &tree);

int main() {
    IntBinaryTree tree;
    ifstream inputFile("codes.txt");
    string code;

    if (!inputFile) {
        cout << "Error opening codes.txt file." << endl;
        return 1;
    }

    // Read codes.txt and populate the tree
    while (getline(inputFile, code)) {
        tree.insertNode(code);
    }

    inputFile.close();

    processChoice(tree);

    return 0;
}

void displayMenu() {
    cout << "\nMenu Options:" << endl;
    cout << "1. Add a code" << endl;
    cout << "2. Delete a code" << endl;
    cout << "3. Search for a code" << endl;
    cout << "4. Modify a code" << endl;
    cout << "5. Display codes In-Order" << endl;
    cout << "6. Display codes Pre-Order" << endl;
    cout << "7. Display codes Post-Order" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

void processChoice(IntBinaryTree &tree) {
    int choice;
    string code;
    string newCode;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); 
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
                if (tree.searchNode(code)) {
                    cout << "Code found in the tree." << endl;
                } else {
                    cout << "Code not found." << endl;
                }
                break;
            case 4:
                cout << "Enter code to modify: ";
                getline(cin, code);
                if (tree.searchNode(code)) {
                    cout << "Enter new code: ";
                    getline(cin, newCode);
                    tree.remove(code);
                    tree.insertNode(newCode);
                    cout << "Code modified." << endl;
                } else {
                    cout << "Code not found." << endl;
                }
                break;
            case 5:
                cout << "Codes in In-Order traversal:" << endl;
                tree.displayInOrder();
                break;
            case 6:
                cout << "Codes in Pre-Order traversal:" << endl;
                tree.displayPreOrder();
                break;
            case 7:
                cout << "Codes in Post-Order traversal:" << endl;
                tree.displayPostOrder();
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please select from the menu." << endl;
        }

    } while (choice != 8);
}
