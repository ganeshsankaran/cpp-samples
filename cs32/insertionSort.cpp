// quadratic-time sorting
// shuffling cards in a hand
// best-case O(n) when everything is sorted

#include <iostream>
using namespace std;

template <class T>
void print(T arr[], size_t len) {
    for(size_t i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T>
void swap(T arr[], size_t a, size_t b) { // essentially a pass by reference for arr
    T temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

template <class T>
void sort(T arr[], size_t len) {
    T item;
    size_t index;

    for(size_t i = 1; i < len; i++) {
        item = arr[i];
        index = i - 1;
        
        while(arr[index] > item && index >= 0) { 
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = item;
    }
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int b[] = {1,10,2,9,3,8,4,7,5,6};
    int c[] = {10,9,8,7,6,5,4,3,2,1};

    cout << "-----a-----" << endl;
    print(a, 10);
    sort(a, 10);
    print(a, 10);

    cout << "-----b-----" << endl;
    print(b, 10);
    sort(b, 10);
    print(b, 10);

    cout << "-----c-----" << endl;
    print(c, 10);
    sort(c, 10);
    print(c, 10);
}