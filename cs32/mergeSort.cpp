// mergesort
// break array into subarrays and merge subarrays to form sorted larger array
// O(nlogn) in any case, O(n) space

#include <iostream>
using namespace std;

template <class T>
void print(T arr[], size_t len) {
    for(int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Precondition: left and right subarrays are sorted
template <class T>
void merge(T arr[], size_t leftLen, size_t rightLen) {
    int* temp;
    size_t index = 0;
    size_t leftIndex = 0;
    size_t rightIndex = 0;

    temp = new int[leftLen + rightLen]; // needs to be on heap if we dont know size until runtime

    while(leftIndex < leftLen && rightIndex < rightLen) {
        if(arr[leftIndex] < (arr + leftLen)[rightIndex]) {
            temp[index++] = arr[leftIndex++];
        }
        else {
            temp[index++] = (arr + leftLen)[rightIndex++];
        }
    }
    while(leftIndex < leftLen) {
        temp[index++] = arr[leftIndex++];
    }
    while(rightIndex < rightLen) {
        temp[index++] = (arr + leftLen)[rightIndex++];
    }

    for(size_t i = 0; i < leftLen + rightLen; i++) {
        arr[i] = temp[i];
    }
    
    delete temp;
}

template <class T>
void sort(T arr[], size_t len) {
    size_t leftLen, rightLen;
    if(len > 1) {
        leftLen = len / 2;
        rightLen = len - leftLen;
        sort(arr, leftLen);
        sort(arr + leftLen, rightLen);
        merge(arr, leftLen, rightLen);
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