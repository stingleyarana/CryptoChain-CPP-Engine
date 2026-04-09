#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct UTXO {
    string tx_id;
    uint32_t index;
    string owner;
    uint64_t value;
};

class UTXOSet {
private:
    vector<UTXO> utxos;

public:
    void addUTXO(UTXO u) {
        utxos.push_back(u);
    }

    uint64_t getBalance(string owner) {
        uint64_t total = 0;
        for (auto& u : utxos) {
            if (u.owner == owner) total += u.value;
        }
        return total;
    }
};

int main() {
    UTXOSet set;
    UTXO u1{"TX001", 0, "ALICE", 500};
    set.addUTXO(u1);
    cout << "余额: " << set.getBalance("ALICE") << endl;
    return 0;
}
