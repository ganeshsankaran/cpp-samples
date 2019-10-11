#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

int binarySearch(int *a, int value, int len) {
    int lower = 0;
    int upper = len - 1;
    int mid = (lower + upper) / 2;
    if(a[mid] == value) {
        return mid;
    }
    else if(a[mid] > value) { // do a binary search from 0 to mid - 1
        return binarySearch(a, value, mid); 
    }
    else { // do a binary search from mid + 1 to lupper
        return binarySearch(a + mid + 1, value, upper - mid) + mid + 1;
        // since the subarray passed above "starts" at 0, add mid + 1 
        // so the final result is with respect to the original array, 
        // the subarray
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    cout << binarySearch(arr, 5, 10) << endl;
    return 0;
}
