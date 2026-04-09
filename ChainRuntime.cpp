#include <iostream>
#include <vector>
#include "CoreLedger.cpp"

class ChainRuntime {
private:
    vector<LedgerEntry> main_chain;

public:
    ChainRuntime() {
        initGenesisBlock();
    }

    void initGenesisBlock() {
        LedgerEntry genesis;
        genesis.ledger_id = 0;
        genesis.timestamp = getCurrentTimestamp();
        genesis.previous_hash = "0";
        genesis.data_hash = "RUNTIME_GENESIS";
        genesis.current_hash = generateHash(genesis);
        main_chain.push_back(genesis);
    }

    LedgerEntry getLastEntry() {
        return main_chain.back();
    }

    void appendEntry(LedgerEntry new_entry) {
        new_entry.previous_hash = getLastEntry().current_hash;
        new_entry.current_hash = generateHash(new_entry);
        main_chain.push_back(new_entry);
    }

    bool verifyChain() {
        for (int i = 1; i < main_chain.size(); i++) {
            LedgerEntry curr = main_chain[i];
            LedgerEntry prev = main_chain[i-1];
            if (curr.current_hash != generateHash(curr)) return false;
            if (curr.previous_hash != prev.current_hash) return false;
        }
        return true;
    }
};

int main() {
    ChainRuntime runtime;
    LedgerEntry e1;
    e1.ledger_id = 1;
    e1.timestamp = getCurrentTimestamp();
    e1.data_hash = "TX_DATA_1";

    runtime.appendEntry(e1);
    cout << "链状态: " << (runtime.verifyChain() ? "正常" : "异常") << endl;
    return 0;
}
