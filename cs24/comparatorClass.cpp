#include <iostream>
#include <array>
#include <queue>

using namespace std;

// do not overload operators for primitives!
class compareClass { // comparator class
public:
    bool operator()(int *a, int *b) const { // functor
        return *a > *b;
    }
};

int main() {
    priority_queue<int*, vector<int*>, compareClass> pq; 
    array<int, 7> arr = {10, 5, 500, 100, 50, 1000, 1};

    for(auto &item : arr) {
        pq.push(&item);
    }

    while(!pq.empty()) {
        cout << *pq.top() << " ";
        pq.pop();
    }
    
    cout << endl;
    return 0;
}