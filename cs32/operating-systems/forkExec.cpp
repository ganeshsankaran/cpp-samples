#include <iostream>
#include <unistd.h>

using namespace std;

#define HELLO_WORLD "helloWorld"

int main() {
    cout << "BEFORE FORK: " << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << endl;
    pid_t result = fork();

    cout << "AFTER FORK: " << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << endl;
    cout << "RESULT PID: " << result << endl;
    cout << "PID: " << getpid() << endl;
     cout << "PPID: " << getppid() << endl;
    if(result == 0) {
        cout << "=====" << endl;
        cout << "RESULT PID: " << result << endl;
        cout << "PID: " << getpid() << endl;
        cout << "PPID: " << getppid() << endl;

        int execvResult;
        char* const path[] = {HELLO_WORLD};
        // if successful, run executable and terminate
        execvResult = execv(HELLO_WORLD, path);

        // if execv results in an error, this code is executed
        perror("execv seems to have failed");
        cerr << "execvResult: " << execvResult << endl;
        exit(1);
    }

    while (waitpid(result, NULL, 0)) {
		if (errno == ECHILD) { // all children of process terminated
			cout << "PID: " << getpid() << " HAS NO CHILDREN" << endl;
			break;
		}
	}
	cout << "AFTER WAITING: " << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << endl;
}