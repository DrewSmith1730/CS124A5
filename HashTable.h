//
// Created by drews on 11/2/2020.
//

#ifndef CS124_HASHTABLE_H
#define CS124_HASHTABLE_H

// If this produces errors, go into CMakeLists.txt and change
// the CMAKE_CXX_STANDARD from 14 to 17.
#if __cplusplus < 17
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
#else
#include <optional>
using std::optional;
using std::nullopt;
using std::make_optional;
#endif

#include <functional>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::vector;

template <typename Hashable>
class HashTable {
private:
    vector<optional<Hashable>> table;
    unsigned long tableSize;

    // Store the function that gets they string key from the Hashable
    function<string(Hashable)> getKey;

    // Hash function
    unsigned long hornerHash(string key) {
        unsigned long hashVal = 0;
        for (char letter : key) {
            hashVal = hashVal * 37 + letter;
        }
        return hashVal % tableSize;
    }

public:
    // Constructor
    HashTable(unsigned long tableSize, function<string(Hashable)> getKey) {
        this->tableSize = tableSize;
        this->getKey = getKey;
        // Make the vector the size of tableSize
        table.resize(tableSize);
    }

    // insert
    void insert(Hashable item) {
        // Get the key from the item
        string key = getKey(item);
        // Hash the key to get an index
        unsigned long index = hornerHash(key);
        // Put the item at that spot in the vector
        table[index] = item;
    }

    // find
    // Return type is optional Hashable because if we find the item,
    // we return it; otherwise, we return nullopt.
    optional<Hashable> find(string key) {
        unsigned long index = hornerHash(key);
        // Check that there is an item at that index
        if (table[index]) {
            // Check if it's the item we're looking for
            if (key == getKey(*table[index])) {
                // We found the item
                return *table[index];
            }
        }
        // We did not find the item
        return nullopt;
    }

    // delete
    optional<Hashable> remove(string key) {
        unsigned long index = hornerHash(key);
        // Check that there is an item at that index
        if (table[index]) {
            // Check if it's the item we're looking for
            if (key == getKey(*table[index])) {
                // We found the item. Delete it.
                Hashable returnItem = *table[index];
                table[index] = nullopt;
                return returnItem;
            }
        }
        // We did not find the item
        return nullopt;
    }

    // print the table
    void printTable() const {
        for (int i = 0; i < tableSize; ++i) {
            cout << i << ": ";
            // If the index of the table has a value
            if (table[i]) {
                // Access the value with * and print it out
                cout << *table[i];
            }
            cout << endl;
        }
    }
};


#endif //CS124_HASHTABLE_H
