#include <stack>
#include <iostream>

class minStack {
public:
    void pop();
    int top() const;
    int min() const;
private:
    std::stack<int> mins;
    std::stack<int> all;
};

void minStack::push(int n) {
    if(!mins.empty()) {
        if(n < mins.top()) {
            mins.push(n);
        }
    }
    else {
        mins.push(n);
    }
    all.push(n);
}

void minStack::pop() {
    if(!all.empty()) {
        if(all.top() == mins.top()) {
            mins.pop();
        }
        all.pop();
    }
}

int minStack::top() const {
    return all.top();
}

int minStack::min() const {
    return mins.top();
}

int main() {
    minStack m;
    m.push(2);
    m.push(1);
    m.push(0);
    m.push(3);
    m.push(-1);

    std::cout << m.min() << std::endl;
    m.pop();
    std::cout << m.min() << std::endl;
    m.pop();
    m.pop();
    std::cout << m.min() << std::endl;

    return 0;
}