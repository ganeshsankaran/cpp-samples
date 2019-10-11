// pick pivot
// elements >/< go to right/left of pivot
// recurse for each left/right portion of array
// O(n^2) on a sorted array
// no extra buffer space required

#include <iostream>
using namespace std;

template <class T>
void print(T arr[], size_t len) {
    for(int i = 0; i < len; i++) {
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
void partition(T arr[], size_t len, size_t& pivotIndex) {
    int pivot = arr[0];
    size_t leftIndex = 1;
    size_t rightIndex = len - 1; 

    while(leftIndex <= rightIndex) {
        while(leftIndex < len && arr[leftIndex] <= pivot) {
            leftIndex++;
        }

        while(arr[rightIndex] > pivot) {
            rightIndex--;
        }

        if(leftIndex < rightIndex) {
            swap(arr, leftIndex, rightIndex);
        }
    }
    swap(arr, pivotIndex, rightIndex);
}

template <class T>
void sort(T arr[], size_t len) {
    size_t pivotIndex;
    size_t leftLen;
    size_t rightLen;

    if(len > 1) {
        partition(arr, len, pivotIndex);
        leftLen = pivotIndex;
        rightLen = len - leftLen - 1;

        sort(arr, leftLen);
        sort(arr + pivotIndex + 1, rightLen);
    }
}

int main() {
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int b[10] = {9,8,7,6,5,4,3,2,1,0};
    int c[10] = {0,9,1,8,2,7,3,6,4,5};

    cout << "---a---" << endl;
    print(a, 10);
    sort(a, 10);
    print(a, 10);
    cout << "---b---" << endl;
    print(b, 10);
    sort(b, 10);
    print(b, 10);
    cout << "---c---" << endl;
    print(c, 10);
    sort(c, 10);
    print(c, 10);
    return 0;
}