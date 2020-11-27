#include <iostream>
#include <fstream>
#include "HashTable.h"

int main() {
    HashTable hashTable;

    /*
     * input file with text to check
     * insert total strings to check
     * inputs all the words into the array
     * inputs all the words into the hash table
     * searches for inputted word until -1
     */
    fstream file("input.in");
    int size;

    file >> size;
    string words[size];

    for(int i = 0; !file.eof(); ++i) { file >> words[i]; }
    file.close();

    for(int i = 0; i < size; i++) { hashTable.insert(words[i]); }
    hashTable.display();

    string input;
    while(true) {
        cout << "Word to search (-1 to cancel): ";
        cin >> input;
        if (input != "-1") {
            cout << hashTable.find(input) << endl;
        } else { break; }
    }
    return 0;
}
