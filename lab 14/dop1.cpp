#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TABLE_SIZE = 100;

// define a hash node
struct HashNode {
    int key;
    int value;
    HashNode* next;
    HashNode(int key, int value) : key(key), value(value), next(NULL) {}
};

// define a hash table
class HashTable {
private:
    HashNode** table;
public:
    HashTable() {
        table = new HashNode * [TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    // hash function using universal hashing
    int hashFunc(int key) {
        int a = rand() % (TABLE_SIZE - 1) + 1;
        int b = rand() % TABLE_SIZE;
        return ((a * key + b) % TABLE_SIZE);
    }

    // insert key-value pair into hash table
    void insert(int key, int value) {
        int hashValue = hashFunc(key);
        HashNode* prev = NULL;
        HashNode* entry = table[hashValue];
        while (entry != NULL) {
            prev = entry;
            entry = entry->next;
        }
        if (entry == NULL) {
            entry = new HashNode(key, value);
            if (prev == NULL) {
                table[hashValue] = entry;
            }
            else {
                prev->next = entry;
            }
        }
        else {
            entry->value = value;
        }
    }

    // search value by key in hash table
    int search(int key) {
        int hashValue = hashFunc(key);
        HashNode* entry = table[hashValue];
        while (entry != NULL) {
            if (entry->key == key) {
                return entry->value;
            }
            entry = entry->next;
        }
        return -1;
    }

    // delete key-value pair from hash table
    void remove(int key) {
        int hashValue = hashFunc(key);
        HashNode* prev = NULL;
        HashNode* entry = table[hashValue];
        while (entry != NULL && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }
        if (entry == NULL) {
            return;
        }
        else {
            if (prev == NULL) {
                table[hashValue] = entry->next;
            }
            else {
                prev->next = entry->next;
            }
            delete entry;
        }
    }

    // display hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode* entry = table[i];
            while (entry != NULL) {
                cout << "[" << entry->key << ": " << entry->value << "]";
                entry = entry->next;
            }
        }
        cout << endl;
    }
};

int main() {
    srand(time(NULL));
    HashTable ht;
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    ht.insert(4, 40);
    ht.insert(5, 50);
    ht.display();
    cout << ht.search(3) << endl;
    ht.remove(4);
    ht.display();
    return 0;
}
