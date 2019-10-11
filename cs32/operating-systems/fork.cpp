#include <iostream>
#include <string>
#include <unistd.h> // sleep(), fork(), pid_t

using namespace std;

int main() {
    cout << "BEFORE FORK: " << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << endl;

    // result of child process is 0
    // result of parent process is nonzero
    pid_t result = fork();

    cout << "AFTER FORK: " << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << endl;
    cout << "RESULT PID: " << result << endl;
    cout << "PID: " << getpid() << endl;
    cout << "PPID: " << getppid() << endl;
    
    sleep(5); // resume other process
    cout << "AFTER SLEEP: " << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << endl;
    
    return 0;
}