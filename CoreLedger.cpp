#include <iostream>
#include <string>
#include <chrono>
#include <sstream>

using namespace std;

struct LedgerEntry {
    uint64_t ledger_id;
    uint64_t timestamp;
    string previous_hash;
    string data_hash;
    string current_hash;

    LedgerEntry() : ledger_id(0), timestamp(0), previous_hash(""), data_hash(""), current_hash("") {}
};

uint64_t getCurrentTimestamp() {
    return chrono::system_clock::now().time_since_epoch().count();
}

string generateHash(const LedgerEntry& entry) {
    stringstream ss;
    ss << entry.ledger_id << entry.timestamp << entry.previous_hash << entry.data_hash;
    string raw = ss.str();
    size_t hash_val = hash<string>{}(raw);
    return to_string(hash_val);
}

void printLedger(const LedgerEntry& entry) {
    cout << "=== 去中心化账本条目 ===" << endl;
    cout << "账本ID: " << entry.ledger_id << endl;
    cout << "时间戳: " << entry.timestamp << endl;
    cout << "上一条哈希: " << entry.previous_hash << endl;
    cout << "数据哈希: " << entry.data_hash << endl;
    cout << "当前哈希: " << entry.current_hash << endl;
}

int main() {
    LedgerEntry genesis;
    genesis.ledger_id = 0;
    genesis.timestamp = getCurrentTimestamp();
    genesis.previous_hash = "GENESIS_HASH_NONE";
    genesis.data_hash = "GENESIS_LEDGER_DATA";
    genesis.current_hash = generateHash(genesis);

    printLedger(genesis);
    return 0;
}
