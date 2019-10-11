#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class BankAccount {
public:
    BankAccount() {
        this->balance = 0;
    }
    void deposit(double amount) {
        m.lock();
        this->balance += amount;
        m.unlock();
    }
    double getBalance() {
        return balance;
    }
private:
    double balance;
    mutex m;
};

void transaction(BankAccount* b, int n) {
    for(int i = 0; i < n; i++) {
        b->deposit(1);
    }
}

int main() {
    BankAccount* b1 = new BankAccount();
    thread t1(transaction, b1, 1000);
    thread t2(transaction, b1, 1000);
    t1.join();
    t2.join();
    cout << b1->getBalance() << endl;
    delete b1;
    BankAccount* b2 = new BankAccount();
    thread t3(transaction, b2, 1000000);
    thread t4(transaction, b2, 1000000);
    t3.join();
    t4.join();
    cout << b2->getBalance() << endl;
    delete b2;
    return 0;
}