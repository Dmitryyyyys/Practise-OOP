#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class HashTable {
private:
    int tableSize; // size of the hash table
    vector<vector<int>> table; // the hash table itself
    int prime; // prime number used for modular hashing

    // hash function using universal hashing
    int hash(int key) {
        int a = rand() % (prime - 1) + 1;
        int b = rand() % prime;
        return ((a * key + b) % prime) % tableSize;
    }

public:
    // constructor
    HashTable(int size, int p) : tableSize(size), prime(p) {
        table.resize(tableSize);
    }

    // insert a key-value pair into the hash table
    void insert(int key, int value) {
        int index = hash(key);
        for (int i = 0; i < table[index].size(); i += 2) {
            if (table[index][i] == key) {
                table[index][i + 1] = value; // update the value
                return;
            }
        }
        table[index].push_back(key);
        table[index].push_back(value);
    }

    // retrieve the value associated with a key
    int get(int key) {
        int index = hash(key);
        for (int i = 0; i < table[index].size(); i += 2) {
            if (table[index][i] == key) {
                return table[index][i + 1];
            }
        }
        return -1; // key not found
    }
};

int main() {
    HashTable table(10, 13); // create a hash table with size 10 and prime 13
    table.insert(1, 10);
    table.insert(2, 20);
    table.insert(3, 30);
    table.insert(4, 40);
    table.insert(5, 50);

    cout << table.get(1) << endl; // output: 10
    cout << table.get(3) << endl; // output: 30
    cout << table.get(6) << endl; // output: -1 (not found)

    return 0;
}
