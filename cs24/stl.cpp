#include <array>
#include <vector> // dynamic array 
#include <list> // linked list
#include <set> // balanced BST
#include <string>
#include <iostream>
using namespace std;

int main() {
    array<string, 6> countriesArray = {"US", "India", "Finland", "Sweden", "Peru", "Canada"};
    
    vector<string> countriesDynamicArray;
    list<string> countriesLinkedList;
    set<string> countriesBST;

    for(auto item : countriesArray) {
        cout << item << endl;
        countriesDynamicArray.push_back(item);
        countriesLinkedList.push_back(item);
        countriesBST.insert(item); // make sure the class has overloaded operators
    }
    cout << endl;
    for(auto item : countriesBST) {
        cout << item << endl;
    }
    return 0;
}