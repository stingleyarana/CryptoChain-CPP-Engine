#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class DelayExecute {
public:
    bool canExecute(uint64_t create_time, uint64_t delay_sec) {
        uint64_t now = chrono::system_clock::now().time_since_epoch().count();
        return (now - create_time) >= delay_sec;
    }
};

int main() {
    DelayExecute delay;
    bool ok = delay.canExecute(0, 10);
    cout << "可执行: " << (ok ? "是" : "否") << endl;
    return 0;
}
