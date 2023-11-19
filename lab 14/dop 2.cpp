#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class HashTable {
private:
    vector<vector<int>> table;
    int size;
    int p;
    int a;
    int b;

    int hash(int key) {
        return ((a * key + b) % p) % size;
    }

public:
    HashTable(int size, int p) {
        this->size = size;
        this->p = p;
        this->a = rand() % (p - 1) + 1; // a is random and in [1, p-1]
        this->b = rand() % p; // b is random and in [0, p-1]
        table.resize(size);
    }

    void insert(int key) {
        int index = hash(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hash(key);
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i] == key) {
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i] == key) {
                table[index].erase(table[index].begin() + i);
                return;
            }
        }
    }

    int get_collisions() {
        int collisions = 0;
        for (int i = 0; i < size; i++) {
            if (table[i].size() > 1) {
                collisions += table[i].size() - 1;
            }
        }
        return collisions;
    }
};

int main() {
    srand(time(NULL));
    HashTable ht(10, 11); // table size 10, prime modulus 11
    ht.insert(1);
    ht.insert(2);
    ht.insert(3);
    ht.insert(4);
    ht.insert(5);
    ht.insert(11); // collides with 0
    ht.insert(22); // collides with 2
    ht.insert(33); // collides with 4
    cout << "Collisions: " << ht.get_collisions() << endl; // expect 3
    ht.remove(2);
    cout << "Collisions: " << ht.get_collisions() << endl; // expect 2
    cout << "Search 2: " << ht.search(2) << endl; // expect 0 (false)
    return 0;
}
