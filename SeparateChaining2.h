//
// Created by drews on 12/2/2020.
//

#ifndef CS124_SEPARATECHAINING2_H
#define CS124_SEPARATECHAINING2_H

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

template<typename Hashable>
class SeparateChaining2 {
private:
    vector<vector<Hashable>> table;
    unsigned long tableSize;

    // The function to get the key from the object
    function<string(Hashable)> getKey;

    // Hash function
    unsigned long hornerHash(string key) {
        unsigned long hashVal = 0;
        for (char &letter : key) {
            hashVal = hashVal * 53 + letter;
        }
        return hashVal % tableSize;
    }

    // Find the next prime number
    int nextPrime(int n) {
        if (n % 2 == 0) {
            ++n;
        }
        bool prime = false;
        while (!prime) {
            prime = true;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            n += 2;
        }
        return (n-2);
    }

public:
    // Constructor
    SeparateChaining2(unsigned long tableSize, function<string(Hashable)> getKey) {
        this->tableSize = nextPrime(tableSize);
        this->getKey = getKey;
        // Make sure the vector has room for tableSize number of elements
        // This will create an empty vector at each index
        table.resize(this->tableSize);
    }

    // insert
    void insert(Hashable item, int* r) {
        // Get the key from the item
        string key = getKey(item);
        // Hash the key to get an index
        unsigned long index = hornerHash(key);
        if (!find(key, r)) {
            // Put the item at that index in the table
            table[index].push_back(item);
            *r = *r + 1;
        }
    }

    // find
    // Return type is optional<Hashable> because if we find the item,
    // we return it; otherwise we return nullopt.
    optional<Hashable> find(string key, int* r) {
        unsigned long index = hornerHash(key);
        // Loop through the items stored at the index
        for (int i = 0; i < table[index].size(); ++i) {
            // Check that the object is the one we're looking for
            if (key == getKey(table[index][i])) {
                // We found the object
                *r = *r + 1;
                return table[index][i];
            }
            *r = *r + 1;
        }
        // We did not find the object
        return nullopt;
    }

    // delete
    optional<Hashable> remove(string key) {
        unsigned long index = hornerHash(key);
        // Loop through the items stored at the index
        for (int i = 0; i < table[index].size(); ++i) {
            // Check that the object is the one we're looking for
            if (key == getKey(table[index][i])) {
                // We found the object. Delete it.
                Hashable returnObject = table[index][i];
                // Use the vector erase method to remove the item.
                table[index].erase(table[index].begin() + i);
                return returnObject;
            }
        }
        // We did not find the object
        return nullopt;
    }

    // printTable
    void printTable() const {
        for (unsigned long i = 0; i < table.size(); ++i) {
            cout << i << ": ";
            // Loop through the items stored at the index
            for (int j = 0; j < table[i].size(); ++j) {
                // Use an * to access the value and print it
                cout << table[i][j] << ", ";
            }
            cout << endl;
        }
    }
};

#endif //CS124_SEPARATECHAINING2_H
