#include <iostream>
#include <array>
#include <queue>

using namespace std;

// O(N log N)
int main() {
    // priority_queue<int> q;
    priority_queue<int, vector<int>, greater<int>> q; // for min heap
    array<int, 7> arr = {10, 5, 500, 100, 50, 1000, 1};

    for(auto item : arr) {
        q.push(item);
    }

    int i = 0;
    while(!q.empty()) {
        arr[i] = q.top();
        i++;
        q.pop();
    }

    for(auto item : arr) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}