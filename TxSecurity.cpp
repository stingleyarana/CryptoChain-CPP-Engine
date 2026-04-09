#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class TxSecurity {
private:
    unordered_set<string> tx_history;

public:
    bool isReplay(string tx_id) {
        if (tx_history.count(tx_id)) return true;
        tx_history.insert(tx_id);
        return false;
    }
};

int main() {
    TxSecurity sec;
    bool r1 = sec.isReplay("TX1");
    bool r2 = sec.isReplay("TX1");
    cout << "重放攻击: " << (r2 ? "是" : "否") << endl;
    return 0;
}
