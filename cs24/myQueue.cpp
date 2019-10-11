#include <iostream>
#include <stack>
#include <string>

using namespace std;

template <class T>
class myQueue {
public:
    void push(T data) {
        while(!main.empty()) {
            sub.push(main.top());
            main.pop();
        }
        main.push(data);
        while(!sub.empty()) {
            main.push(sub.top());
            sub.pop();
        }
    }
    void pop() {
        if(!main.empty()) {
            main.pop();
        }
    }
    T front() {
        return main.top();
    }
    bool empty() {
        return main.empty();
    }
private:
    stack<T> main;
    stack<T> sub;
};

int main() {
    myQueue<int> q;
    q.push(1);
    q.push(3);
    q.push(2);
    q.push(4);
    q.pop();
    
    cout << q.front() << endl;

    myQueue<string> q2;
    q2.push("one");
    q2.push("three");
    q2.push("two");
    q2.push("four");
    q2.pop();
    q2.pop();
    q2.pop();

    cout << q2.front() << endl;
    q2.pop();
    cout << q2.empty() << endl;
    return 0;
}