#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void printArray(array<int,10> &arr) { // use & for efficiency
    for(int item: arr) {
        cout << item << " ";
    }
    cout << endl;
 }

void printVector(vector<int> &vec) { // use & for efficiency
    for(int item: vec) {
        cout << item << " ";
    }
    cout << endl;
}

template <class T> 
void print(T& arr) { // take in parameter of a generate type T using template
    for(auto item: arr) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    srand(time(NULL));

    array<int, 10> arr;
    for(int &item: arr) { // use & to modify the actual item, not make a copy
        item = rand() % 100 + 1;
    }
    printArray(arr);
    
    vector<int> vec;
    for(int i = 0; i < 10; i++) {
        vec.push_back(rand() % 100 + 1);
    }
    cout << "Vector before sort: ";
    printVector(vec);
    cout << "Vector after sort: ";
    sort(vec.begin(), vec.end());
    print(vec);
    cout << vec[5] << endl;

    list<int> ll;
    for(int i = 0; i < 10; i++) {
        ll.push_back(rand() % 100 + 1);
    }
    cout << "List before sort: ";
    print(ll);
    cout << "List after sort: ";
    ll.sort(); // different sort because linked list doesn't support random access
    print(ll);
}