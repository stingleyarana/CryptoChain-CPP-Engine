#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class StateAccount {
private:
    unordered_map<string, uint64_t> balances;

public:
    void setBalance(string addr, uint64_t val) {
        balances[addr] = val;
    }

    uint64_t getBalance(string addr) {
        if (balances.count(addr)) return balances[addr];
        return 0;
    }

    void transfer(string from, string to, uint64_t val) {
        if (balances[from] >= val) {
            balances[from] -= val;
            balances[to] += val;
        }
    }
};

int main() {
    StateAccount state;
    state.setBalance("A", 1000);
    state.transfer("A", "B", 300);
    cout << "A余额: " << state.getBalance("A") << endl;
    cout << "B余额: " << state.getBalance("B") << endl;
    return 0;
}
