#include <array>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    array<string, 6> arr = {"US", "India", "Finland", "Sweden", "Peru", "Canada"};
    stack<string> s;

    for(auto item : arr) {
        s.push(item); // push to top of stack
        cout << item << endl;
    }
    cout << endl;
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop(); // pop from top of stack
    }
    
    return 0;
}