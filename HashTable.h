//
// Created by Collin Stratton on 11/18/20.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#define SIZE 17
#define HASH 17

using namespace std;

struct Node {                               // creating the node and initializing its values
    string data = "/0";
    struct Node* next = nullptr;
};

class HashTable {
private:
    struct Node* bucketArray[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; ++i) {    // initializing the bucketArray values
            bucketArray[i] = nullptr;
        }
    };

    void insert(string newData) {           // inserts a new data into the bucketArray
        struct Node* newNode = new Node;
        newNode->data = newData;
        int x = 0;

        /*
         * turns the string into a integer value by summing its chars
         */
        for (int i = 0; i < newData.length(); i++) { x += newData[i]; }

        /*
         * hashes the integer value and inserts it into the bucketArray
         */
        newNode->next = bucketArray[x % HASH];
        bucketArray[x % HASH] = newNode;
    }

    void display() {                        // displays the contents of the bucketArray
        struct Node* temp = new struct Node;

        /*
         * loops through the entire size of the array and outputs all values
         * in the case of a linked list, the loop searches for the next node to equal null
         */
        for(int i = 0; i < SIZE; i++) {
            temp = bucketArray[i];
            cout << i << ". ";
            while(temp != NULL) {
                cout << temp->data << " - ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    bool find(string lookup) {              // finds the value the user inputs within the bucketArray
        struct Node* temp;
        int count = 0;

        /*
         * for loop takes the inputted string and turns it into an integer value
         * the integer value is then hashed to equal the position in the hash table
         */
        for(int i = 0; i < lookup.length(); i++) { count += lookup[i]; }
        int x = count % HASH;
        temp = bucketArray[x];

        /*
         * if no data at position then value is not in the bucket array
         */
        if(bucketArray[x] == nullptr) {
            cout << "Not here " << endl;;
            return false;
        }

        /*
         * since data is found (based on the previous if statement), check if its at the top value
         * else dive into the linked list until found
         */
        if(bucketArray[x]->data == lookup) {
            cout << "found at index " << x << endl;
            return true;
        } else {
            while (temp != nullptr) {
                if(temp->data == lookup) {
                    cout << "found at index " << x << endl;
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
    }

};


#endif //HASHTABLE_HASHTABLE_H
