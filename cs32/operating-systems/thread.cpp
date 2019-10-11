#include <iostream>
#include <thread>
#include <unistd.h>
#include <string>

using namespace std;

void callback1(string str, int num) {
    cout << "***Thread " << this_thread::get_id() << "***" << endl;
    cout << "str: " << str << endl;
    cout << "num: " << num << endl;
}

void callback2(bool createThread) {
    cout << "***Thread " <<this_thread::get_id() << "***" << endl;
    if(createThread) {
        cout << '\t';
        thread t(callback2, false);
        t.join();
    }
}

int main() {
    thread t1(callback1, "one", 1); // function pointer with args
    //t1.detach(); would cause main to terminate, so no output
    t1.join(); // make sure t1 finishes before main
    thread t2(callback2, true);
    t2.join();
    thread t3(callback2, false);
    t3.join();
    return 0;
}