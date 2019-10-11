#include <iostream>
#include <queue>
#include <vector>
using namespace std;

double median(vector<int>& v) {
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int, vector<int>, less<int>> max;

    for(auto i : v) {
        min.push(i);
        max.push(i);
    }

    while(1) {
        min.pop();
        max.pop();
        if(min.top() >= max.top()) {
            return (min.top() + max.top()) / 2.0;
        }
    }
}

int main() {
    vector<int> v1 = {3, 1, 4, 1, 5, 9};
    vector<int> v2 = v1;
    v2.push_back(2);
    cout << median(v1) << endl;
    cout << median(v2) << endl;
    return 0;
}