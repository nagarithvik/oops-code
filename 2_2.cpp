#include <iostream>
#include <string>
using namespace std;

// level defaults to 1 (INFO)
void logMsg(const string &msg, int level = 1) {
    const string tag[] = {"", "INFO", "WARN", "ERROR"};
    cout << "[" << tag[level] << "] " << msg << endl;
}

// Simple interest with a default rate of 7.5%
double interest(double principal, double years, double rate = 7.5) {
    return principal * rate * years / 100.0;
}

int main() {
    logMsg("System started");
    logMsg("Low memory", 2);

    cout << "Interest = " << interest(10000, 2) << endl;
    cout << "Interest = " << interest(10000, 2, 9.0) << endl;

    return 0;
}