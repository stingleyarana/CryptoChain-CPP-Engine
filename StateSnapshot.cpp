#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class StateSnapshot {
private:
    unordered_map<string, uint64_t> snapshot;

public:
    void save(unordered_map<string, uint64_t> state) {
        snapshot = state;
    }

    unordered_map<string, uint64_t> rollback() {
        return snapshot;
    }
};

int main() {
    StateSnapshot snap;
    unordered_map<string, uint64_t> state = {{"A", 1000}};
    snap.save(state);
    auto recover = snap.rollback();
    cout << "恢复余额: " << recover["A"] << endl;
    return 0;
}
